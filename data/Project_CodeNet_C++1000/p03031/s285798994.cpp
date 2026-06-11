#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (1e9)
#define INFL (1e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>using arr=vector<vector<T>>;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    int n,m; cin >> n >> m;
    vector<int> p(m);
    arr<int> G(n);
    rep(i, m){
        int k; cin >> k;
        rep(j, k){
            int s; cin >> s;
            G[--s].push_back(i);
        }
    }
    rep(i, m) cin >> p[i];

    vector<int> on(m);
    int ans=0;
    rep(bit, 1<<n){
        rep(i, m) on[i] = 0;
        rep(i, n) {
            if(bit>>i & 1){
                for(int j: G[i]) on[j] = (on[j]+1)%2;
            }
        }

        bool flag = true;
        rep(i, m) {
            if(on[i] != p[i]) {
                flag = false;
                break;
            }
        }

        if(flag) {
            // cout << bitset<10>(bit) << endl;
            ans++;
        }
    }
    pr(ans);
    return 0;}