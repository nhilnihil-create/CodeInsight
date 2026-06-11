#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    string s;
    cin >> s;
    ll ans = 0;
    for(auto e : s) ans += (e == '+' ? 1 : -1);
    cout << ans << endl;
    return 0;
}