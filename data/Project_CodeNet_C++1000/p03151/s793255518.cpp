#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n;
    cin>>n;
    vector<int>a(n),b(n),x;
    ll sum=0;
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    int cnt=0;
    rep(i,n){
        if(a[i]-b[i]<0)sum+=b[i]-a[i],cnt++;
        else x.push_back(a[i]-b[i]);
    }
    sort(x.begin(),x.end());
    while(sum>0&&!x.empty()){
        sum-=x.back();
        x.pop_back();
        cnt++;
    }
    if(sum>0)cout<<-1<<endl;
    else cout<<cnt<<endl;
}