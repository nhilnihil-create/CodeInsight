#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back

int main() {

    string s ;
    cin >> s ;
    ll n = s.size() - 1 ;
    ll ans = 0 , a = 0 ;

    for (ll i = 0 ; i< n ; i++) {
        if (s[i]=='A') a++ ;
        else if (s[i]=='B') {
            if (s[i+1]=='C') ans+=a,i++ ;
            else a= 0 ;
        }
        else {
            a = 0 ;
        }
    }
    cout << ans << endl ;
}
