#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    string S;
    cin >> N >> S;
    int cnt[26] = {};
    for(int i = 0; i < S.size(); i++) {
        cnt[S[i]-'a']++;
    }
    int ans = 1;
    for(int i = 0; i < 26; i++) {
        ans*=(cnt[i]+1);
        ans = ans%INF;
    }
    cout << ans-1 << endl;
}
