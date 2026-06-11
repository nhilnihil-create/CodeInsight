#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
int MOD=1000000007;
signed main(){
    int a,b;cin>>a>>b;
    if(b%a==0)cout<<a+b<<endl;
    else cout<<b-a<<endl;
    return 0;
}