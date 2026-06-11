#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    string s; cin>>s;

    int ans=0;
    while(s.size()>1){
        char f=s.front(),b=s.back();
        if(f==b){
            s=s.substr(1,s.size()-2);
        }else if(f=='x' || b=='x'){
            if(f=='x') s=s.substr(1,s.size()-1);
            else s=s.substr(0,s.size()-1);
            ans++;
        }else{
            ans=-1;
            break;
        }
    }

    cout<<ans<<endl;
}