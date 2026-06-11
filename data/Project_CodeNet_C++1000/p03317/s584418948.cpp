#include<bits/stdc++.h>
#define INFTY 1<<20
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const int MOD=1000000007;

//最大公約数
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}

int a[100010];


int main(){
    int n,k,num;cin>>n>>k;
    int a[n];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)num=i;
    }
    int ans=0;
    if((n-k)%(k-1)==0)ans = 1+(n-k)/(k-1);
    else ans = 2+(n-k)/(k-1);

    cout<<ans<<endl;
return 0;
}