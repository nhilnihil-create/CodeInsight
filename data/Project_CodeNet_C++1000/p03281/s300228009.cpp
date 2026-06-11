#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 1; 2 * i - 1 <= N; ++i) {
        int num = 2 * i - 1;
        int cnt = 0;
        for (int j = 1; j <= num; ++j) {
            if (num % j == 0) ++cnt;
        }
        if (cnt == 8) ++ans;
    }
    cout << ans << endl;
}
