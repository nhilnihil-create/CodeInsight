#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int r = n-1;
    while(s[r] == 'B'){
        r--;
        if(r < 0)break;
    }
    ll ans = 0;
    for(int i = r; i >= 0; i--){
        if(s[i] == 'B'){
            ans += r - i;
            r--;
        }
    }
    cout << ans << endl;
}