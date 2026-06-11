#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main(){
    int N,M;
    cin >> N >> M;
    map<int,int>Mp;
    for(int i = 0; i < N; i++) {
        int K;cin >> K;
        for(int j = 0; j < K; j++) {
            int A;cin >> A;
            Mp[A]++;
        }
    }
    int ans = 0;
    for(P x:Mp) {
        if(x.second == N) {
            ans++;
        }
    }
    cout << ans << endl;
}
