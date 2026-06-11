#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

const string YES = "Yes";
const string NO = "No";

void solve(std::string s, std::string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<char>());
    if (s < t) {
        cout << YES << endl;
    } else {
        cout << NO << endl;
    }
}

int main() {
    std::string s;
    std::cin >> s;
    std::string t;
    std::cin >> t;
    solve(s, t);
    return 0;
}
