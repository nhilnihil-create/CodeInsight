#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> h(n);
    rep(i,n) cin>>h[i];
    sort(h.begin(),h.end(),greater<int>());
    int minv=1000000005;
    rep(i,n-k+1) minv=min(minv,h[i]-h[i+k-1]);
    cout<<minv<<"\n";
    return 0;
}