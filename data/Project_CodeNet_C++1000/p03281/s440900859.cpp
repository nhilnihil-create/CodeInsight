#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;

int main(){
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i += 2) {
        int tmp = 0;
        for (int j = 1; j <= n; ++j) {
            if (i % j == 0) tmp++;
        }
        if (tmp == 8) cnt++;
    }
    cout << cnt << endl;
}