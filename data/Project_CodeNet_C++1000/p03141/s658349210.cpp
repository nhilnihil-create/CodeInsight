#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main(){
    int N;
    cin >> N;
    vector<int>cnt;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int A,B;cin >> A >> B;
        cnt.push_back(A+B);
        ans-=B;
    }
    sort(cnt.rbegin(),cnt.rend());
    for(int i = 0; i < N; i+=2) {
        ans+=cnt[i];
    }
    cout << ans << endl;
}
