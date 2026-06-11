#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ll a,b;
    cin >> a >> b;
    ll ans = 0;
    while(a <= b){
        a *= 2;
        ans++;
    }
    cout << ans << endl;
}