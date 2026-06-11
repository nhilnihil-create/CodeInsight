#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<bitset>
#include<unordered_map> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fio ios_base::sync_with_stdio(false)
#define li long long int
#define ll int
#define readi(x) scanf("%d",&x)
#define  reads(x)  scanf("%s", x)
#define readl(x) scanf("%lld",&x)
#define rep(i,n) for(i=0;i<n;i++)
#define revp(i,n) for(i=(n-1);i>=0;i--)
#define myrep1(i,a,b) for(i=a;i<=b;i++)
#define myrep2(i,a,b) for(i=b;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
#define MAXN 100000000000000005
#define MINN -10000000000000000
#define INTMAX 1000001000
#define pii pair<ll,ll> 
#define pdd pair<double,double>
#define pic pair<int,char>
#define N 5005
#define lgn 20
#define ddouble long double
#define minus minu
#define PI 3.1415926535
#define lgn 20
using namespace std;
li a[16][16];li n,inf=10000000000000000;li A[1<<16];li sum[1<<16];
void pre(){
    li i,j,k,c;
for(i=(1<<n)-1;i>=0;i--){c=0;
A[i]=inf;
    for(j=0;j<n;j++){
        for(k=j+1;k<n;k++){
if(((1<<j)&i) && ((1<<k)&i)){c=c+a[j][k];}
        }
    }
    sum[i]=c;
}    
}

li ff(li i){
    if(i==0) return(0);
    if(A[i]!=inf) return(A[i]);
li j;li ans=-10000000000000000;
for(j=i;j>0;j=((j-1)&i))
{
ans=max(ans,sum[j]+ff(i^j));
}
A[i]=ans;return(A[i]);
}

int main(){li i,j;readl(n);
for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            readl(a[i][j]);
        }
    }
pre();
li ans=ff((1<<n)-1);cout<<ans;    
}