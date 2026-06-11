#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin>>s;
    int one=0;
    int zero=0;
    rep(i,s.size()){
        if(s[i]=='0')zero+=1;
        else one+=1;

    }
    int aho=min(one,zero);
    int ans=aho*2;
    cout<<ans<<endl;
}