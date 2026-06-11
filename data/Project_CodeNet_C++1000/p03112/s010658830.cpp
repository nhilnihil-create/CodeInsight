#include <bits/stdc++.h>
#include <unordered_map>

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
ll countDigit(ll n) { return floor(log10(n) + 1); } 
typedef pair <ll,ll> P;
static const ll dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};

template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) 
{ 
    for (int i = 0; i < (int)v.size(); ++i) os << v[i] << " ";  
    return os; 
}

template <typename T1, typename T2> 
ostream& operator<<(ostream& os, const map<T1, T2>& m) 
{ 
    for (auto p : m) os << "<" << p.first << ", " << p.second << "> "; 
    return os; 
}

int main()
{
    ll A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> s(A);
    rep(i, A) { 
        cin >> s[i];
    }
    s.push_back(-1000000000000);
    s.push_back(1000000000000);
    vector<ll> t(B);
    rep(i, B) { 
        cin >> t[i];
    }
    t.push_back(-1000000000000);
    t.push_back(1000000000000);
    sort(all(s));
    sort(all(t));
    rep(i, Q) {
        ll x;
        cin >> x;
        auto sleft_iter = lower_bound(all(s), x);
        sleft_iter--;
        ll sleft = s[distance(s.begin(), sleft_iter)];
        ll sright = *upper_bound(all(s), x);

        auto tleft_iter = lower_bound(all(t), x);
        tleft_iter--;
        ll tleft = t[distance(t.begin(), tleft_iter)];
        ll tright = *upper_bound(all(t), x);

        vector<ll> tmp;
        tmp.push_back(abs(sright-x) + abs(sright-tright));
        tmp.push_back(abs(tright-x) + abs(tright-sright));
        tmp.push_back(abs(sright-x) + abs(sright-tleft));
        tmp.push_back(abs(tright-x) + abs(tright-sleft));
        tmp.push_back(abs(sleft-x) + abs(sleft-tleft));
        tmp.push_back(abs(tleft-x) + abs(tleft-sleft));
        tmp.push_back(abs(sleft-x) + abs(sleft-tright));
        tmp.push_back(abs(tleft-x) + abs(tleft-sright));
        sort(all(tmp));
        print(tmp[0]);
    }
    return 0;
}