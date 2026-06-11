#include <bits/stdc++.h>
#define int long long
#define rep(i, a, n) for(int (i) = (int)(a);(i) < (int)(n);++(i))
#define repe(i, a, n) for(int (i) = (int)(a);(i) <= (int)(n);++(i))
#define repif(i, a, x) for(int (i) = (int)(a);(x);++(i))
#define repr(i, a, n) for(int (i) = ((int)(a)-1);(i) >= (int)(n);--(i))
#define reper(i, a, n) for(int (i) = (int)(a);(i) >= (int)(n);--(i))
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define RNG(x, a, n) &((x)[a]), &((x)[n])
#define ADD(a, b) ((((a+MOD)%MOD)+((b+MOD)%MOD))%MOD)
#define MUL(a, b) ((((a)%MOD)*((b)%MOD))%MOD)
#define CEIL(x) ((int)ceil(((double)x)))
#define POW(x, y) ((int)pow(x, y))
#define UNIQUE(x) (x).erase(unique(ALL((x))), (x).end())
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define yes cout << "yes" << endl;
#define no cout << "no" << endl;
#define fcout cout << fixed << setprecision(10)
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define PI (acos(-1))
#define EPS (1e-10)
#define INF LLONG_MAX
#define MOD 1000000007
using namespace std;
using VI = vector<int>;
using PII = pair<int, int>;
using VPII = vector<PII>;
template<typename T, typename C>
using PQ = priority_queue<T, vector<T>, C>;
using Complex = complex<double>;


int N, K;
VPII v;
map<int, bool> m;
PQ<int, greater<int>> pq0;
PQ<int, less<int>> pq1;


signed main(){
    cin >> N >> K;
    rep(i, 0, N){
        int t, d;
        cin >> t >> d;
        v.pb({ d, t });
    }

    sort(ALL(v), greater<PII>());

    int ans = 0, n = 0;
    rep(i, 0, N){
        if(i < K){
            ans += v[i].first;
            if(m[v[i].second]) pq0.push(v[i].first);
            else m[v[i].second] = true, n++;
        }
        else if(!m[v[i].second]) pq1.push(v[i].first), m[v[i].second] = true;
    }
    ans += n*n;
    
    int prev = ans;
    repe(i, n+1, K){
        if(pq0.empty() || pq1.empty()) break;
        int v0, v1;
        v0 = pq0.top(), pq0.pop();
        v1 = pq1.top(), pq1.pop();
        prev = prev-v0-(i-1)*(i-1)+v1+i*i;
        chmax(ans, prev);
    }

    cout << ans << endl;

    return 0;
}