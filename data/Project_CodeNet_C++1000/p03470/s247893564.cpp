#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
int N;
vector<int> D;


void input() {
    cin >> N;
    D = vector<int>(N);
    rep(i, N) cin >> D[i];
}


int main() {
    input();
    set<int> s;
    rep(i, N) s.insert(D[i]);
    int ans = s.size();
    cout << ans << endl;
}
