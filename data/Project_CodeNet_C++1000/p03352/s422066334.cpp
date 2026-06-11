#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int x;
    cin >> x;

    int ans = 0;
    for (int i = 1; i < 35; i++) {
        for (int j = 2; j < 10; j++) {
            int a = 1;
            for (int k = 0; k < j; k++) {
                a *= i;
            }
            if (a <= x) ans = max(ans, a);
        }
    }
    cout << ans << endl;

    return 0;
}