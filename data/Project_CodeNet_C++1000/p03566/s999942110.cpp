#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for (ll i = (ll)(n) - 1; i >= 0; i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define INF (1LL << 62)

#define PI (acos(-1))
#define print(x) cout << x << endl
 
ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
typedef pair <ll,ll> P;

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
    }else{
        return a.second > b.second;
    }
}

template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) 
{ 
    for (int i = 0; i < (int)v.size(); ++i) { 
        os << v[i]; 
        if (i != (int)v.size() - 1) 
            os << " "; 
    } 
    return os; 
} 

int main()
{
    ll N;
    cin >> N;
    vector<double> t(N);
    vector<double> v(N);
    vector<double> l(N);
    vector<double> r(N);
    double sum = 0.;
    rep(i, N) { 
        cin >> t[i];
        l[i] = sum;
        sum += t[i];
        r[i] = sum;
    }
    rep(i, N) {
        cin >> v[i];
    }
    v.insert(v.begin(), 0);
    v.push_back(0);
    l.insert(l.begin(), 0);
    l.push_back(sum);
    r.insert(r.begin(), 0);
    r.push_back(sum);
    vector<vector<double>> vel(N+2);
    rep(i, N+2) {
        for (double time = 0; time <= sum; time += 0.5) {
            if (time < l[i]) {
                vel[i].push_back(v[i] + (l[i] - time));
            } else if (l[i] <= time && time <= r[i]) {
                vel[i].push_back(v[i]);
            } else if (r[i] <= time) {
                vel[i].push_back(v[i] + (time - r[i]));
            } else {
                vel[i].push_back(0);
            }
        }
    }
    double ret = 0.;
    rep(i, vel[0].size()-1) {
        double upper = 1000;
        double bottom = 1000;
        rep(j, vel.size()) {
            upper = min(upper, vel[j][i]);
            bottom = min(bottom, vel[j][i+1]);
        }
        ret += (upper + bottom) * 0.5 / 2.0;
    }
    cout.precision(20);
    print(fixed << ret);
    return 0;
}