#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    string s;
    cin>>n>>s;
    vector<int>sume(n+1);
    vector<int>sumw(n+1);
    rep(i,n){
       if(s[i]=='W')sumw[i+1]=sumw[i]+1;
       else sumw[i+1]=sumw[i];
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='E')sume[i]=sume[i+1]+1;
        else sume[i]=sume[i+1];
    }
    int ans=1000000;
    for(int i=0;i<n;i++){
        int cnt;
        cnt=sumw[i]+sume[i+1];
        ans=min(cnt,ans);
        
    }
    cout<<ans<<endl;
}