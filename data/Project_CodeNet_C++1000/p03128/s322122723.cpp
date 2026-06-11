#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt[9] = {2,5,5,4,5,6,3,7,6};
string dp[10005];
signed main() {
    int N,M;
    cin >> N >> M;
    vector<bool>A(9,false);
    for(int i = 0; i < M; i++) {
        int a;
        cin >> a;
        a--;
        A[a] = true;
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < 9; j++) {
            if(A[j]) {
                if(i >= cnt[j]) {
                    if(i-cnt[j] != 0 && dp[i-cnt[j]] == "") {
                        continue;
                    }
                    bool ok = false;
                    string S = dp[i-cnt[j]];
                    for(int k = 0; k < S.size(); k++) {
                        if(S[k]-'0' <= j) {
                            ok = true;
                            S = S.substr(0,k)+to_string(j+1)+S.substr(k,S.size()-k);
                            break;
                        }
                    }
                    if(!ok) {
                        S += to_string(j+1);
                    }
                    if(dp[i].size() < S.size()) {
                        dp[i] = S;
                    }
                    else if(dp[i].size() == S.size() && dp[i] < S) {
                        dp[i] = S;
                    }
                }
            }
        }
    }
    cout << dp[N] << endl;
}
