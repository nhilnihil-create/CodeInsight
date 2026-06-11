#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b;
    cin >> a >> b;
    a--;
    ll fa=0;
    if(a%2==0) fa=a;
    if(((a+1)/2)%2==0) fa^=1;

    ll fb=0;
    if(b%2==0) fb=b;
    if(((b+1)/2)%2==0) fb^=1;

    ll ans=fa^fb;
    cout << ans << "\n";
    return 0;
}