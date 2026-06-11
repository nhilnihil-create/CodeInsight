#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
string S;


void input() {
    cin >> S;
}


int main() {
    input();
    set<char> s{'A', 'C', 'G', 'T'};
    int n = S.size();
    int ans = 0;
    int i, c= 0;
    while (i < n) {
        if (s.count(S[i])) {
            c++;
            ans = max(ans, c);
        } else {
            c = 0;
        }
        i++;
    }
    cout << ans << endl;
}
