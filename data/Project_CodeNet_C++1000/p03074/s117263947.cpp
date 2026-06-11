#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n,k; string s;
    cin>>n>>k>>s;
    vector<int>a;
    int x=0;
    rep(i,n)if(s[i]=='1')x++;
    if(x==s.size()){cout<<x<<endl; return 0;}
    if(s[0]=='0')a.push_back(0);
    int cnt=1;
    rep(i,n-1){
        if(s[i]==s[i+1])cnt++;
        else a.push_back(cnt),cnt=1;
    }
    if(s[n-1]==s[n-2])a.push_back(cnt);
    else a.push_back(1);
    if(s[n-1]=='0')a.push_back(0);
    if(a.size()/2<k){cout<<s.size()<<endl; return 0;}
    int cnt2=0;
    rep(i,2*k+1)cnt2+=a[i];
    int ans=cnt2;
    for(int i=1; i<a.size()-2*k; i+=2){
        cnt2-=a[i]+a[i-1];
        cnt2+=a[i+2*k]+a[i+2*k+1];
        ans=max(ans,cnt2);
    }
    cout<<ans<<endl;
    return 0;
}