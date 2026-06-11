#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n,t,a;
    cin>>n>>t>>a;
    int minv=INT_MAX;
    int ans=0;
    rep(i,n){
        int h;
        cin>>h;
        int c;
        c=t*1000-h*6-a*1000;
        if(c<0) c=-c;
        if(minv>c){
            minv=c;
            ans=i;
        }
    }
    cout<<ans+1<<"\n";
    return 0;
}