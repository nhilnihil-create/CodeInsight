#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main(){
    int N,x;
    cin >> N >> x;
    vector<int>a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int ans = 0;
    sort(a.begin(),a.end());
    for(int i = 0; i < N; i++) {
        if(x >= a[i]) {
            ans++;
            x-=a[i];
        }
    }
    if(ans == N && x) {
        cout << N-1 << endl;
    }
    else {
        cout << ans << endl;
    }
}
