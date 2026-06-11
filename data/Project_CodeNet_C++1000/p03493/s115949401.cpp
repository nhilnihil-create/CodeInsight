#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define rep(i,s,e) for(int i=s;i<e;i++)
#define endl '\n'
int main(){
    string s;cin>>s;
    int res=0;
    rep(i,0,3){
        if(s[i]=='1')res++;
    }
    cout<<res<<endl;
}