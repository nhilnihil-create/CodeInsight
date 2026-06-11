#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll l = a + b, r = c + d;
    if(l == r) cout << "Balanced" << endl;
    else if(l > r) cout << "Left" << endl;
    else cout << "Right" << endl;
    return 0;
}