#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    vector<int> es[N][2];
    int num[N][2];
    rep(i, M){
        int a, b; cin >> a >> b; a--, b--;
        es[a][S[b]-'A'].pb(b);
        es[b][S[a]-'A'].pb(a);
    }
    rep(i, N){
        rep(j, 2) num[i][j] = sz(es[i][j]); 
    }
    queue<int> que;
    vector<bool> rem(N, false);
    rep(i, N){
        if(!num[i][0] || !num[i][1]) que.push(i);
    }
    while(!que.empty()){
        int i = que.front();
        que.pop();
        if(rem[i]) continue;
        if(num[i][0] && num[i][1]) continue;
        rem[i] = true;
        int k = S[i]-'A';
        rep(j, 2){
            for(auto &e: es[i][j]){
                num[e][k]--;
                que.push(e);
            }
        }
    }
    bool res = true;
    rep(i, N) res &= rem[i];
    if(!res) cout << "Yes" << endl;
    else cout << "No" << endl;
}