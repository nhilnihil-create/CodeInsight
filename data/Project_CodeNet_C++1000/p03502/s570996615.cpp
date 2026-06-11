#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
string N;


void input() {
    cin >> N;
}


int ctoi(char c) {
    return c - '0';
}


int f(string s) {
    int ret = 0;
    for (char c : s) {
        ret += ctoi(c);
    }
    return ret;
}


int main() {
    input();
    int x = stoi(N);
    string ans;
    if (x % f(N) == 0) ans = "Yes";
    else ans = "No";
    cout << ans << endl;
}
