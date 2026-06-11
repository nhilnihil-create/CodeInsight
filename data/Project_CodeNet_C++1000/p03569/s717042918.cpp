#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;




int main(){
    string s;cin>>s;
    ll l=0,r=s.size()-1,lx=0,rx=0,ans=0;
    while(l<=r){
        lx=0;rx=0;
        while(s.at(l)=='x'){
            l++;
            lx++;
            if(l==s.size()){
                cout<<0<<endl;
                return 0;
            }
        }
        while(s.at(r)=='x'){
            r--;
            rx++;
        }
        if(s.at(l)!=s.at(r)){
            cout<<-1<<endl;
            return 0;
        }
        ans+=abs(lx-rx);
        l++;
        r--;
    }
    cout<<ans<<endl;
    
}





