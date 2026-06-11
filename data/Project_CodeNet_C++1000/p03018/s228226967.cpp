#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};
signed main() {
    string S;
    cin >> S;
    S+="Z";
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < S.size()-1; i++) {
        if(S[i] == 'A') {
            cnt++;
        }
        else if(S[i] == 'B' && S[i+1] == 'C') {
            ans+=cnt;
            i++;
        }
        else {
            cnt = 0;
        }
    }
    cout << ans << endl;
}
