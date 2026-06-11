#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=unsigned long long;
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    string s;
    cin>>s;

    if(s[a]!='-'){
        cout<<"No"<<"\n";
        return 0;
    }

    rep(i,a){
        if(s[i]=='-'){
            cout<<"No"<<"\n";
            return 0;
        }
    }
        for(int i=a+1;i<=a+b;i++){
        if(s[i]=='-'){
            cout<<"No"<<"\n";
            return 0;
        }
    }
    cout<<"Yes"<<"\n";
    return 0;
}