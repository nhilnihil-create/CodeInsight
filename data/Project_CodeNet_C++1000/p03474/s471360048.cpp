#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
int A, B;
string S;


void input() {
    cin >> A >> B >> S;
}


int main() {
    input();
    int c = count(S.cbegin(), S.cend(), '-');
    string ans;
    if (S[A] == '-' && c == 1) ans = "Yes";
    else ans = "No";
    cout << ans << endl;
}
