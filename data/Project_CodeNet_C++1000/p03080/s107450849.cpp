#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n; string s;
    cin>>n>>s;
    int cnt1=0,cnt2=0;
    rep(i,n){
        if(s[i]=='R')cnt1++;
        if(s[i]=='B')cnt2++;
    }
    if(cnt1>cnt2)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}