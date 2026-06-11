#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    int ans = 1001001;
    for(int i = 1; i <= n/2; i++){
        int a = n - i;
        int b = i;
        int cnt = 0;
        rep(i, 6){
            cnt += a % 10;
            cnt += b % 10;
            a /= 10;
            b /= 10;
        }
        ans = min(ans, cnt);
    } 
    cout << ans << endl;
}