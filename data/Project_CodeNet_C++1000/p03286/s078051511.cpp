#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    ll n; cin >> n;
    string ans = "";

    ll k = 0;
    while(n != 0){
        if((n - (ll)pow(-2,k)) % (ll)pow(-2,k+1) == 0) { ans = '1' + ans; n -= (ll)pow(-2,k); }
        else ans = '0' + ans;
        k++;
    }
    if(ans.length()) cout << ans << endl;
    else cout << "0" << endl;
}