#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main() {
    ll n;
    cin >> n;
    int ans = 0;
    if(n < 10) cout << n << endl;
    else{
        n++;
        string tmp = to_string(n);
        while(n > 10) n /= 10;
        if(n != 10) ans += n-1;
        rep(i, tmp.size()-1) ans += 9;
        cout << ans << endl;
    }
}