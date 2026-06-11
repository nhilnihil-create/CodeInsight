#include <bits/stdc++.h>
using namespace std;
#define int long long
int N,A,B,C;
int l[8];
vector<int>sentaku[4];
int ans = 10020201010;
signed dfs(int n) {
    if(n == N) {
        if(sentaku[0].size() > 0 && sentaku[1].size() > 0 && sentaku[2].size() > 0) {
            int cnt1 = 0;
            int cnt2 = 0;
            int cnt3 = 0;
            for(int i = 0; i < sentaku[0].size(); i++) {
                cnt1+=sentaku[0][i];
            }
            for(int i = 0; i < sentaku[1].size(); i++) {
                cnt2+=sentaku[1][i];
            }
            for(int i = 0; i < sentaku[2].size(); i++) {
                cnt3+=sentaku[2][i];
            }
            int Z = N-sentaku[3].size();
            ans = min(ans,abs(A-cnt1)+abs(B-cnt2)+abs(C-cnt3)+(Z-3)*10);
            return 0;
        }
        else {
            return 0;
        }
    }
    else {
        sentaku[0].push_back(l[n]);
        dfs(n+1);
        sentaku[0].pop_back();
        sentaku[1].push_back(l[n]);
        dfs(n+1);
        sentaku[1].pop_back();
        sentaku[2].push_back(l[n]);
        dfs(n+1);
        sentaku[2].pop_back();
        sentaku[3].push_back(l[n]);
        dfs(n+1);
        sentaku[3].pop_back();
    }
        return 0;
}
signed main() {
    cin >> N >> A >> B >> C;
    for (int i = 0; i < N; i++) {
        cin >> l[i];
    }
    dfs(0);
    cout << ans << endl;
}