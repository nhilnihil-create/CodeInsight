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
    int N, Y; cin >> N >> Y;
    int fukuzawa = -1, ichiyoh = -1, hideyo = -1;
    for(int yukichi = 0; yukichi <= N; yukichi++) for(int higuchi = 0; higuchi <= N - yukichi; higuchi++) {
        int noguchi = N - yukichi - higuchi;
        int otoshidama = 10000 * yukichi + 5000 * higuchi + 1000 * noguchi;
        if(otoshidama == Y) {
            fukuzawa = yukichi; ichiyoh = higuchi; hideyo = noguchi;
            break;
        }
    }
    cout << fukuzawa << ' ' << ichiyoh << ' ' << hideyo << endl;
    return 0;
}
