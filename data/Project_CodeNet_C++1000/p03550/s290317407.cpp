#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000007 // 10^9+7
#define INF 99999999999 //10^12-1
#define dev 998244353 //tenka1
#define P pair<int,int>
#define F first
#define S second
int n,z,w;
int a[3000];
signed main(){
    cin>>n>>z>>w;
    rep(i,n)cin>>a[i];
    if(n==1){
        cout<<abs(w-a[0])<<endl;
    }
    else{
        int x=abs(a[n-2]-a[n-1]),y=abs(a[n-1]-w);
        cout<<max(x,y)<<endl;
    }
    return 0;
}
