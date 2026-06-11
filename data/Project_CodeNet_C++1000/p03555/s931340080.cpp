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
    vector<vector<char>> C(2, vector<char>(3));
    for(int i = 0; i < 2; i++) for(int j = 0; j < 3; j++) cin >> C[i][j];
    if(C[0][0] == C[1][2] && C[0][1] == C[1][1] && C[0][2] == C[1][0]) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}