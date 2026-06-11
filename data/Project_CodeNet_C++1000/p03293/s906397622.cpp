#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s,t;
    cin>>s>>t;
    int sabs=s.size();
    s+=s;
    bool ok=false;
    rep(i,sabs){
        if(s.substr(i,sabs)==t){
            ok=true;
            break;
        }
    }
    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}