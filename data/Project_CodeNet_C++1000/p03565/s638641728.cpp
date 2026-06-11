#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    string S, T; cin >> S >> T;
    if(S.size() < T.size()) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    else {
        string s = S;
        bool judge = false;
        for(int i = S.size() - T.size(); i >= 0; i--) {
            bool can = true;
            for(int j = 0; j < T.size(); j++) {
                if(S[i + j] != T[j] && S[i + j] != '?') {
                    can = false;
                    break;
                }
            }
            if(can) {
                judge = true;
                for(int j = 0; j < S.size(); j++) {
                    if(s[j] == '?') s[j] = 'a';
                }
                for(int j = 0; j < T.size(); j++) {
                    s[i + j] = T[j];
                }
                break;
            }
        }
        if(judge) cout << s << endl;
        else cout << "UNRESTORABLE" << endl;
        return 0;
    }
}
