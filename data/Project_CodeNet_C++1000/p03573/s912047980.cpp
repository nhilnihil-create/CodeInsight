#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i< (int)(b); ++i)
using namespace std;
const int mod=1e9+7;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int a,b,c,ans; cin >> a >> b >> c;
    if(a==b) ans=c;
    if(b==c) ans=a;
    if(c==a) ans=b;
    cout << ans << endl;
 }    
