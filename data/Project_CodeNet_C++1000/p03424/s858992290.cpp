#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
int N;
vector<char> S;


void input() {
    cin >> N;
    S = vector<char>(N);
    rep(i, N) cin >> S[i];
}


int main() {
    input();
    set<char> s;
    rep(i, N) s.insert(S[i]);
    int n = s.size();
    string ans;
    if (n == 3) ans = "Three";
    else ans = "Four";
    cout << ans << endl;
}
