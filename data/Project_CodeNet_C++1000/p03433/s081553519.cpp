#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
int N, A;


void input() {
    cin >> N >> A;
}


int main() {
    input();
    string ans;
    if (N % 500 <= A) ans = "Yes";
    else ans = "No";
    cout << ans << endl;
}
