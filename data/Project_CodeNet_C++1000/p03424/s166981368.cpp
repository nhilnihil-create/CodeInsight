#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    string ans = "Three";
    rep(i, 0, n) {
        char c;
        cin >> c;
        if(c == 'Y') ans = "Four";
    }
    cout << ans << endl;
    return 0;
}