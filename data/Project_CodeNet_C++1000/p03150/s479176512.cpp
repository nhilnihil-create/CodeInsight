#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 , -1};
signed main() {
    string S = "keyence";
    string T;
    cin >> T;
    for(int i = 0; i <= 7; i++) {
        if(T.substr(0,i)+T.substr(T.size()-7+i) == S) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
