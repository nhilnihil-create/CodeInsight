#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;

ll M = 1000000007;

int main(){
    ll N, C; cin >> N >> C;
    vvll p(N, vll(3));
    rep(i, 0, N){
        cin >> p[i][0] >> p[i][1] >> p[i][2];
    }
    sort(p.begin(),p.end());
    vector<vector<P>> cp(C+1, vector<P>(0));
    rep(i, 0, N){
        ll a = p[i][0], b = p[i][1], c = p[i][2];
        P x = mp(a,b);
        cp[c].emplace_back(x);
    }
    vvll Q(0, vll(2));
    rep(i, 1, C+1){
        ll n = sz(cp[i]);
        if(n == 0){continue;}
        P m = cp[i][0];
        ll b = m.first, e = m.second;
        if(n == 1){
            vll t(2); t[0] = b; t[1] = e;
            Q.emplace_back(t);
        }
        rep(j, 1, n){
            P v = cp[i][j];
            ll g = v.first, h = v.second;
            if(j == n-1){
                if(g == e){
                    e = h;
                    vll r(2);
                    r[0] = b; r[1] = e;
                    Q.emplace_back(r);
                }else{
                    vll r(2);
                    r[0] = b; r[1] = e;
                    Q.emplace_back(r);
                    vll u(2);
                    u[0] = g; u[1] = h;
                    Q.emplace_back(u);
                }
            }
            else{
                if(g == e){
                    e = h; continue;
                }else{
                    vll r(2);
                    r[0] = b; r[1] = e;
                    Q.emplace_back(r);
                    b = g; e = h;
                }
            }
        }
    }
    sort(Q.begin(),Q.end());
    priority_queue<ll, vector<ll>, greater<ll>> E;
    ll ma = 1;
    E.push(Q[0][1]);
    ll n = sz(Q);
    rep(i, 1, n){
        ll x = Q[i][0], y = Q[i][1];
        ll z = E.top();
        if(z < x){
            E.pop();
            E.push(y);
        }else{
            E.push(y);
        }
        ma = max(ma, sz(E));
    }
    prt(ma);
}