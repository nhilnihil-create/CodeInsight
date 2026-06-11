#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;

int main(){
    int N,K; cin >> N >> K;
    vector<ll> x(N), y(N);
    rep(i,N) cin >> x[i] >> y[i];

    ll ans = INF;

    rep(i,N){
        rep(j,N){
            rep(k,N){
                rep(l,N){
                    ll x1 = x[i];
                    ll x2 = x[j];
                    ll y1 = y[k];
                    ll y2 = y[l];
                    int count = 0;
                    rep(m,N){
                        if (x1 <= x[m] && x[m] <= x2 && y1 <= y[m] && y[m] <= y2){
                            count++;
                        }
                    }

                    if (count >= K){
                        ans = min(ans, abs(x1-x2)*abs(y1-y2));
                    }

                }
            }
        }
    }

    cout << ans << endl;
}