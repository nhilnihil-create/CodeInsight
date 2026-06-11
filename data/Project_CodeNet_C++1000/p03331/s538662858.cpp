#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int w(int n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    int ans = inf;
    for(int i = 1; i <= n / 2; i++) {
        int a = i;
        int b = n - i;
        int anss = w(a) + w(b);
        ans = min(ans, anss);
    }

    cout << ans << endl;

    return 0;
}