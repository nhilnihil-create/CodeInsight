#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N; cin >> N;
    set<string> visit;
    string W; cin >> W;
    char z = W.at(W.size() - 1);
    string ans = "Yes";
    visit.insert(W);
    for (int i = 0; i < N - 1; i++) {
        cin >> W;
        if (visit.count(W)) {
            ans = "No";
            break;
        }
        visit.insert(W);
        if (W.at(0) != z) {
            ans = "No";
            break;
        }
        z = W.at(W.size() - 1);
    }
    cout << ans << endl;
}