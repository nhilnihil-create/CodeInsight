#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1234567;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    string S;
    cin >> S;
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == 'W') {
            ans+=i-cnt;
            cnt++;
        }
    }
    cout << ans << endl;
}
