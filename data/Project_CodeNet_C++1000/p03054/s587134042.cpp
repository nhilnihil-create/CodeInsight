#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> P;
int main(){
    int h,w,n,sr,sc;
    string s,t;
    cin>>h>>w>>n>>sr>>sc>>s>>t;
    int x=1;
    int xr=sr,xc=sc;
    rep(i,n){
        if(s[i]=='U') xr--;
        if(xr<=0||xr>h||xc<=0||xc>w) x=0;
        if(t[i]=='D'&&xr!=h) xr++;
    }
    xr=sr,xc=sc;
    rep(i,n){
        if(s[i]=='D') xr++;
        if(xr<=0||xr>h||xc<=0||xc>w) x=0;
        if(t[i]=='U'&&xr!=1) xr--;
    }
    xr=sr,xc=sc;
    rep(i,n){
        if(s[i]=='R') xc++;
        if(xr<=0||xr>h||xc<=0||xc>w) x=0;
        if(t[i]=='L'&&xc!=1) xc--;
    }
    xr=sr,xc=sc;
    rep(i,n){
        if(s[i]=='L') xc--;
        if(xr<=0||xr>h||xc<=0||xc>w) x=0;
        if(t[i]=='R'&&xc!=w) xc++;
    }
    if(x) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
}