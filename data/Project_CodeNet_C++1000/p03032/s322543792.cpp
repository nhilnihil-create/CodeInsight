#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int64_t INF = 1LL << 60;
const int INF = 1 << 29;
//const int MODINF = 1000000007;
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> V(N), W(N);
    rep(i, 0, N) cin >> V.at(i);
    W = V;
    reverse(all(W));
    int ans_max = 0;
    rep(i, 0, min(N, K) + 1){
        rep(j, 0, min(N, K) + 1 - i){
            vector<int> X(0);
            rep(k, 0, i){
                X.push_back(V.at(k));
            }
            rep(k, 0, j){
                X.push_back(W.at(k));
            }
            sort(all(X));
            //rep(k, 0, X.size()) cout << X.at(k) << " ";
            //cout << endl;
            
            int l = 0, ans = 0;
            rep(k, 0, X.size()){
                if (X.at(k) < 0 && l < K - X.size()){
                    l++;
                    continue;
                }
                else ans += X.at(k);
            }
            ans_max = max(ans_max, ans);
        }
    }
    cout << ans_max << endl;
}