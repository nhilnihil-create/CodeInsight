#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,M;
    cin >> N >> M;
    vector<P>AB(N);
    for(int i = 0; i < N; i++) {
        cin >> AB[i].first >> AB[i].second;
    }
    sort(AB.begin(),AB.end());
    int ans = 0;
    int cnt = 0;
    while(M) {
        if(M >= AB[cnt].second) {
            M-=AB[cnt].second;
            ans+=AB[cnt].first*AB[cnt].second;
            cnt++;
        }
        else {
            ans+=AB[cnt].first*M;
            M = 0;
        }
    }
    cout << ans << endl;
}
