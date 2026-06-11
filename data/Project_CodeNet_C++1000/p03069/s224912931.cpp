#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    string S;
    cin >> N >> S;
    int cnt = 0,ans = 0;;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == '.') {
            ans++;
        }
    }
    cnt = ans;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == '.') {
            cnt--;
        }
        else {
            cnt++;
        }
        ans = min(ans,cnt);
    }
    cout << ans << endl;
}
