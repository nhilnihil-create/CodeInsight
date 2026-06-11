#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    string S;
    cin >> S;
    int X = 0;
    int Y = 0;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == '0') {
            X++;
        }
        else {
            Y++;
        }
    }
    cout << min(X,Y)*2 << endl;
}
