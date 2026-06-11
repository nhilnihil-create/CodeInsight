#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int N;
    cin >> N;

    string ans = "No";

    for (int i = 0; i <= 25; ++i) {
        for (int j = 0; j <= 15; ++j) {
            if (4*i+7*j == N) {
                ans = "Yes";
                break;
            }
        }
    }

    cout << ans << endl;


    return 0;
}