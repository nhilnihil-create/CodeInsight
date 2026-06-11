#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 100000;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    string S;
    cin >> N >> S;
    vector<P>sum(N+1);
    int A = 0,B = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == '#') {
            A++;
            sum[i+1].first = sum[i].first+1;
            sum[i+1].second = sum[i].second;
        }
        else {
            B++;
            sum[i+1].second = sum[i].second+1;
            sum[i+1].first = sum[i].first;
        }
    }
    if(A == N || B == N) {
        cout << 0 << endl;
        return 0;
    }
    int ans = INF;
    for(int i = 0; i < N; i++) {
        int cnt = sum[i+1].first;
        cnt+=(B-sum[i+1].second);
        ans = min(ans,cnt);
    }
    ans = min(ans,A);
    ans = min(ans,B);
    // . . . . . . # # # # # #
    cout << ans << endl;
}
