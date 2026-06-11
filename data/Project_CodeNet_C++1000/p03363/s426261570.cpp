#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    vector<int>cnt(N+1);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        cnt[i+1] += A[i];
    }
    for(int i = 0; i < N; i++) {
        cnt[i+1]+=cnt[i];
    }
    sort(cnt.begin(),cnt.end());
    int ans = 0;
    int sum = 1;
    for(int i = 1; i <= N; i++) {
        if(cnt[i] == cnt[i-1]) {
            sum++;
        }
        else {
            ans+=(sum*(sum-1))/2;
            sum = 1;
        }
    }
    if(sum != 1) {
        ans+=(sum*(sum-1))/2;
    }
    cout << ans << endl;
}
