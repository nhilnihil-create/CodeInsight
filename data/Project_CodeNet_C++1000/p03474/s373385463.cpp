#define _GLIBCXX_DEBUG
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
    int A, B; cin >> A >> B;
    string S; cin >> S;
    string ans = "Yes";
    if(S.size() != A + B + 1) ans = "No";
    else {
        for(int i = 0; i < S.size(); i++) {
            if(i != A && S[i] == '-') {
                ans = "No";
                break;
            }
            else if (i == A && S[i] != '-') {
                ans = "No";
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}