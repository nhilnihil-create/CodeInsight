#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main(){
    int N;
    cin >> N;
    int ans = 0;
    for(int i = 1; i <= N; i+=2) {
        int cnt = 0;
        for(int j = 1; j <= i; j++) {
            if(i%j == 0) {
                cnt++;
            }
        }
        if(cnt == 8) {
            ans++;
        }
    }
    cout << ans << endl;
}
