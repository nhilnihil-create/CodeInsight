#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 ,-1};
signed main(){
    int N,K;
    cin >> N >> K;
    int ans = 0;
    for(int i = K+1; i <= N; i++) {
        ans+=N/i*(i-K);
        if(N%i >= K) {
            ans+=N%i-K;
            if(K) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
