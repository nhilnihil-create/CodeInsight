#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long ;
const int INF = 1001001001;

int main() {

    string s ; 
    cin >> s ;

    ll num = 0 ;
    ll ans = 0 ;
    for(ll i=0;i<s.length();++i)
    {
        if(s[i]=='B'){
            num++;
        } 
        else {
            ans+=num ;
        }
    }

   //cout << num << endl ;
   cout << ans << endl ;

    return 0 ;
}