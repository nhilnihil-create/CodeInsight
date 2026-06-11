#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
int N;
vector<int> L;


void input() {
    cin >> N;
    L = vector<int>(N);
    rep(i, N) cin >> L[i];
}


int main() {
    input();
    int s = 0;
    rep(i, N) s += L[i];
    int m = *max_element(L.begin(), L.end());
    string ans;
    if (m < s - m) ans = "Yes";
    else ans = "No";
    cout << ans << endl;
}
