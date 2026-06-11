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
    cin >> N;
    vector<string>S(N);
    for(int i = 0; i < N; i++) {
        cin >> S[i];
    }
    int A = 0,B = 0,C = 0;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 1; j < (int)S[i].size(); j++) {
            if(S[i][j] == 'B' && S[i][j-1] == 'A') {
                ans++;
                j++;
            }
        }
        if(S[i][0] == 'B') {
            if(S[i][(int)S[i].size()-1] == 'A') {
                C++;
            }
            else {
                B++;
            }
        }
        if(S[i][S[i].size()-1] == 'A' && S[i][0] != 'B') {
            A++;
        }
    }
    if(A+B == 0 && C > 0) {
        C--;
    }
    cout << ans+min(A,B)+C << endl;
}