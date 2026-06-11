#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
int R, G;


void input() {
    cin >> R >> G;
}


int main() {
    input();
    int ans = 2 * G - R;
    cout << ans << endl;
}
