#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
using lint=long long;
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
    int n;cin>>n;
    vector<lint> a(n);
    vector<lint> b(n);
    lint sm=0;
    lint mn=1e18;
    bool flag=true;
    rep(i,n){
        cin>>a[i]>>b[i];
        sm+=a[i];
        if(a[i]!=b[i])flag=false;
        if(a[i]>b[i]){
            mn=min(mn,b[i]);
        }
    }
    lint res=sm-mn;
    if(res<0)res=0;
    if(flag)res=0;
    cout<<res<<"\n";
    return 0;
}