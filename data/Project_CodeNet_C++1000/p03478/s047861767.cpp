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
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int c = 0;
        int d = i;
        for(int j = 0; j < 5; j++) {
            c += d % 10;
            d /= 10;
        }
        if(c >= a && c <= b) ans+=i;
    }

    cout << ans << endl;

    return 0;
}