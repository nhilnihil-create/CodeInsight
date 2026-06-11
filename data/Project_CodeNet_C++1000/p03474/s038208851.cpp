#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int a,b;
    string s;
    cin>>a>>b>>s;
    if(s[a]!='-'){
        cout<<"No"<<endl;
        return 0;
    }
    bool ok=true;
    rep(i,s.size()){
        if(i!=a && '0'<=s[i] && s[i]<='9')ok=true;
        else if(i==a){
            ok=true;
        }
        else{
            ok=false;
            break;
        }
    }
    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}