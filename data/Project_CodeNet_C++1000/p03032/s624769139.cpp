#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,K;
    cin >> N >> K;
    vector<int>V(N);
    for(int i = 0; i < N; i++) {
        cin >> V[i];
    }
    int ans = 0;
    for(int i = 0; i <= min(N,K); i++) {
        for(int j = 0; i+j <= min(N,K); j++) {
            int cnt = 0;
            vector<int>res = {};
            for(int k = 0; k < i; k++) {
                cnt += V[k];
                if(V[k] < 0) {
                    res.push_back(V[k]);
                }
            }
            for(int k = N-1; k >= N-j; k--) {
                cnt += V[k];
                if(V[k] < 0) {
                    res.push_back(V[k]);
                }
            }
            sort(res.begin(),res.end());
            for(int k = 0; k < res.size() && k < K-i-j;  k++) {
                cnt += abs(res[k]);
            }
            ans = max(ans,cnt);
        }
    }
    cout << ans << endl;
}
