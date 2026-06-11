#include <bits/stdc++.h>

using namespace std;
#define int long long
int MOD = 1000000007;


signed main(){
    string S;
    cin >> S;
    
    if(regex_match(S,regex("A?KIHA?BA?RA?"))) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}
