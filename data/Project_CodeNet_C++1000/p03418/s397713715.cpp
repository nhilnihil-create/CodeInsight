#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<cmath>
#include<string>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=3e6;
int main (){
    int n,k;
    cin>>n>>k;
    ll ans=0;
    for(int i=1;i<=n;i++){
        int t,m;
        t=n/i,m=n%i;
        if(k==0) ans+=max(0,i-k)*t+max(0,m-k);
        else   ans+=max(0,i-k)*t+max(0,m-k+1);
     //   printf ("%lld\n",ans);
    }
    printf ("%lld\n",ans);





}
