#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,M;
    cin >> N >> M;
    int ans = 0;
    vector<int>A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<P>vec(M);
    for(int i = 0; i < M; i++) {
        int B,C;
        cin >> B >> C;
        vec[i].first = C;
        vec[i].second = B;
    }
    sort(A.begin(),A.end());
    sort(vec.begin(),vec.end());
    int cnt = M-1;
    for(int i = 0; i < N; i++) {
        if(vec[cnt].first <=A[i]) {
            continue;
        }
        A[i] = vec[cnt].first;
        vec[cnt].second--;
        if(vec[cnt].second == 0) {
            cnt--;
        }
    }
    for(int i = 0; i < N; i++) {
        ans+=A[i];
    }
    cout << ans << endl;
}