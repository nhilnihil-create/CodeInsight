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
    string S; cin >> S;
    ll K; cin >> K;
    int cnt = 0, save;
    for (int i = 0; i < S.size(); i++) {
        if (S.at(i) == '1') {
            cnt++;
        }
        else {
            save = i;
            break;
        }
    }
    if (cnt >= K) {
        cout << 1 << endl;
    }
    else {
        cout << S.at(save) << endl;
    }
    return 0;
}