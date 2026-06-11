#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    string s,t;
    cin>>s>>t;
    size_t l=s.length();
    bool flag=false;
    rep(i,l){
        if(s==t){
            flag=true;
            break;
        }
        s=s.back()+s.substr(0,l-1);
    }
    if(flag) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
    return 0;
}