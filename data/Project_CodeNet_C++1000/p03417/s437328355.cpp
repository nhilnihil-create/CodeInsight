#include<bits/stdc++.h>
#define INFTY 1<<20
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const int MOD=1000000007;
int n;
int x[102],cnt=0;

int main(){
    
    ll n,m;
    cin>>n>>m;
    ll ans;
    if(n==1&&m==1)ans = 1;
    else if(n==1||m==1)ans = n*m-2;
    else ans = n*m-2*(n+m-2);
    cout<< ans <<endl;
return 0;
}