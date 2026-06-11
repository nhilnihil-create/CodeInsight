#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#define mx 1000008

#define pii pair<int,int>
#define pi acos(-1.0)
#define pb push_back
#define ss second
#define ff first
typedef long long int ll;
///adjacent move
int fx[4]={0,+1,0,-1};
int fy[4]={+1,0,-1,0};
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
///knight
ll prime[mx];
void seive()
{
    for(int i=2;i<mx;i+=2) prime[i]=2;
    for(int i=3;i<mx;i+=2) prime[i]=i;
    ll sq=sqrt(mx);
    for(int i=3;i<=sq;i+=2){
        if(prime[i]==i){
            for(int j=i*i;j<mx;j+=i){
                if(prime[j]==j) prime[j]=i;
            }
        }
    }
}
double a[1000004];
double dp[3004][3003];
ll n;
ll mid;
double cal(ll pos,ll tails)
{
    if(pos> n + 1)return 0;
    if(pos== n + 1){
		if(tails < mid)return 1;
		else return 0;
	}
    if(dp[pos][tails]!=-1) return dp[pos][tails];
    return dp[pos][tails]=a[pos]*cal(pos+1,tails)+((1.0-a[pos])*cal(pos+1,tails+1));
}
int main()
{
    //seive();
    int t=1;
    //cin>>t;
    int c=0;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        mid=n/2+1;
        for(int i=0;i<=3000;i++) for(int j=0;j<=3000;j++) dp[i][j]=-1.0;
        cout<<setprecision(10)<<fixed;
        cout<<cal(1,0)<<endl;;
    }
}
