#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main(){
    lol a,ans[100]={};
    string s,t;
    cin>>a;
    ans[0]=2;
    ans[1]=1;
    for(lol i=2;i<=a;i++){
        ans[i]=ans[i-1]+ans[i-2];
    }
    cout<<ans[a]<<"\n";
    return(0);
}