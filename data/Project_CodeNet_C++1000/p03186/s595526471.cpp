#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int A,B,C;
    cin >> A >> B >> C;
    cout << min(A,C)+B+min(B+1,max(0LL,C-A)) << endl;
}
