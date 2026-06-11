#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    string s;
    int k;
    cin>>s;
    cin>>k;
    rep(i,k){
        if(s[i]!='1'){
            cout<<s[i]<<"\n";
            return 0;
        }
    }
    cout<<1<<"\n";
    return 0;
}