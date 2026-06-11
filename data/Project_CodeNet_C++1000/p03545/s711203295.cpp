#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
    string s;cin>>s;
    rep(i,4)s[i]-='0';
    
    rep(i,1<<3){
        int ans = s[0];
        rep(j,3)ans += (1&i>>j)?s[j+1]:(-s[j+1]);
        if(ans!=7)continue;
        
        cout<<(int)s[0];
        rep(j,3)printf("%c%d",(1&i>>j)?'+':'-',s[j+1]);
        cout<<"=7\n";
        return 0;
    }
}