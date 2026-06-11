#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;


int main(){
    int n;
    string s;   cin >> n >> s;
    ll bc=0, wc=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='#') bc += 1;
        else wc += 1;
    }
    ll ans=bc;
    bc = 0;
    for(int i=0; i<n; i++){
        ans = min(ans, bc+wc);
        if(s[i]=='#') bc += 1;
        else wc -= 1;
    }
    
 
    cout << ans << endl;
}

