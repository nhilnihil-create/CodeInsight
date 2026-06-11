#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>x(m);
    rep(i,m) cin>>x[i];
    vector<int>sa(m-1);
    sort(x.begin(),x.end());
    if(n>m){
        cout<<0<<endl;
        return 0;
    }else{
        rep(i,m-1)sa[i]=x[i+1]-x[i];

    }
    sort(sa.begin(),sa.end());
    int ans=0;
    rep(i,m-n)ans+=sa[i];
    cout<<ans<<endl;
}