#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    int ans = 1e9;
    for(int A = 1; A < (1<<n); ++A){
        int la = 0, costA = 0;
        rep(i,n){
            if(A>>i & 1){
                la += l[i];
                ++costA;
            }
        }
        for(int B = 1; B < (1<<n); ++B){
            bool okB = true;
            int lb = 0, costB = 0;
            rep(i,n){
                if((A>>i & 1) && (B>>i & 1)) okB = false;
                if(B>>i & 1){
                    lb += l[i];
                    ++costB;
                }
            }
            if(!okB) continue;
            for(int C = 1; C < (1<<n); ++C){
                bool okC = true;
                int lc = 0, costC = 0;
                rep(i,n){
                    if(C>>i & 1){
                        if((A>>i & 1) || (B>>i & 1)) okC = false;
                        lc += l[i];
                        ++costC;
                    }
                }
                if(!okC) continue;
                int cost = (costA + costB + costC - 3) * 10;
                cost += abs(la - a) + abs(lb - b) + abs(lc - c);
                chmin(ans, cost);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
