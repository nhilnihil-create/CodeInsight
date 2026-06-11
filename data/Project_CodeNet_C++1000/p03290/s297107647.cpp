#include <bits/stdc++.h>
using namespace std; 
#define int long long
int INF = 1e9+7;
signed main() {
    int D,G;
    cin >> D >> G;
    vector<int>P(D);
    vector<int>C(D);
    for(int i = 0; i < D; i++) {
        cin >> P[i] >> C[i];
    }
    int ans = INF;
    for(int bit = 0; bit < (1 << D); bit++) {
        int cnt = 0; 
        int cnt2 = 0;
        int MAX = 0;
        for(int i = 0; i < D; i++) {
            if(1 & (bit >> i)) {
                cnt+=(i+1)*100*P[i]+C[i];
                cnt2+=P[i];
            }
            else {
                MAX = i+1;
            }
        }
        if(cnt < G) {
            int X = (G-cnt+MAX*100-1)/(MAX*100);
            if(X >= P[MAX-1]) {
                continue;
            }
            cnt2+=X;
        }
        ans = min(ans,cnt2);
    }
    cout << ans << endl;
}