#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (int i = int(x); i < (int)(n); i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
using ll = long long;

int main() {
    ll n;
    cin >> n;

    vector<ll> a;
    bool isNF = true;
    ll cnt = 0;

    a.push_back(n);
    
    while (isNF) {
        ll nNum;
        cnt++;

        if (n % 2 == 0) {
            nNum = n / 2;
        } else {
            nNum = n * 3 + 1;
        }

        rep(i, cnt - 1) {
            if (nNum == a[i]) {
                isNF = false;
            }
        }

        n = nNum;
        a.push_back(nNum);
    }

    cout << cnt + 1 << endl;
}