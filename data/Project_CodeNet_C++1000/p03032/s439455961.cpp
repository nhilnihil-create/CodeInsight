#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main(){
    int N,K;
    cin >> N >> K;
    vector<int>V(N);
    for(int i = 0; i < N; i++) {
        cin >> V[i];
    }
    int ans = 0;
    for(int i = 0; i <= min(N,K); i++) {
        for(int j = 0; j <= min(N-i,K-i); j++) {
            vector<int>cnt = {};
            int sum = 0;
            for(int k = 0; k < i; k++) {
                sum += V[k];
                if(0 > V[k]) cnt.push_back(V[k]);
            }
            for(int k = 0; k < j; k++) {
                sum += V[N-k-1];
                if(0 > V[N-k-1]) cnt.push_back(V[N-k-1]);
            }
            sort(cnt.begin(),cnt.end());
            for(int k = 0; k < min((int)cnt.size(),K-i-j); k++) {
                sum += -cnt[k];
            }
            ans = max(ans,sum);
        }
    }
    cout << ans << endl;
}