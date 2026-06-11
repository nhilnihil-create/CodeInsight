#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
string N;


void input() {
    cin >> N;
}


int main() {
    input();
    bool a = N[0] == N[1] && N[1] == N[2];
    bool b = N[1] == N[2] && N[2] == N[3];
    string ans;
    if (a || b) ans = "Yes";
    else ans = "No";
    cout << ans << endl;
}
