#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353
#define Graph vector<vector<int>>

int main() {
    int N; cin >> N;
    string S; cin >> S;
    vector<int> W(N), E(N);
    int ans = inf, recW = 0, recE = 0;
    for (int i = 0; i < N; i++) {
        if (S.at(i) == 'W') {
            W.at(i) += 1 + recW;
            recW = W.at(i);
            E.at(i) = recE;
        }
        else {
            E.at(i) += 1 + recE;
            recE = E.at(i);
            W.at(i) = recW;
        }
    }
    for (int i = 0; i < N; i++) {
        if (S.at(i) == 'W') {
            ans = min(ans, W.at(i) - 1 + E.at(N - 1) - E.at(i));
        }
        else {
            ans = min(ans, W.at(i) + E.at(N - 1) - E.at(i));
        }
    }
    cout << ans << endl;
}