/*#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int SIZE = 1e6+5;
char str[SIZE];
ll l[SIZE];
ll r[SIZE];
ll rsum[SIZE];
ll rr[SIZE];
int main(){
    int n;scanf("%d",&n);
    scanf("%s",str+1);
    int q;scanf("%d",&q);
    for(int i = 1;i <= n;i++){
        if(str[i]=='D'){
            l[i] = l[i-1]+1;
            r[i] = r[i-1];
            rsum[i] = rsum[i-1];
            rr[i] = rr[i-1];
        }
        else if(str[i]=='M'){
            l[i] = l[i-1];
            r[i] = l[i-1];
            rsum[i] = rsum[i-1]+r[i];
            rr[i] = rr[i-1]+1;
        }
        else{
            l[i] = l[i-1];
            r[i] = r[i-1];
            rsum[i] = rsum[i-1];
            rr[i] = rr[i-1];
        }
    }


    while(q--){
        int k;scanf("%d",&k);
        ll res = 0;
        for(int i=1;i<=n;i++){
            if(str[i]=='C'){
                if(i>k)res += rsum[i]-rsum[i-k]-l[i-k]*(rr[i]-rr[i-k]);
                else res += rsum[i];
            }
        }
        printf("%lld\n",res);




    }
}

*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <stack>
#include <bitset>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;
ll a[1010];
ll ass[1010];
ll as[500050];
int bit[65];
int main()
{
    //cout<<(((1<<(4-1))&8))<<endl;
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        ass[i]=a[i]+ass[i-1];
    }
    int tot=0;
    ll maxn=-1;
    for(int i=0;i<=n-1;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            as[++tot]=ass[j]-ass[i],maxn=max(maxn,as[tot]);
           // cout<<as[tot]<<endl;
        }

    }
    //cout<<"maxn="<<maxn<<endl;
    n=tot;
    int st=0,x=maxn;
    for(int i=0;i<64;i++)
    {
        if(x<pow(2,i)) break;
       // if(((1<<(i−1))&x)>0)
       // {
        //    st=i;
        //}
        if((((1ll*1)<<(i))&x)>0)
            st=i;
    }
    //cout<<"st="<<st<<endl;
    ll asum=0;
    for(ll i=40;i>=0;i--)
    {

        int tsum=0;
        for(int j=1;j<=n;j++)
        {
            if(as[j]==-1) continue;
            if(((1ll*1)<<i)>as[j]) continue;
            if((((1ll*1)<<(i))&as[j])>0)
            {
                tsum++;
            }
        }
        if(tsum>=k)
        {
             for(int j=1;j<=n;j++)
             {
                if(as[j]==-1) continue;
                if((((1ll*1)<<(i))&as[j])<=0)
                {
                    as[j]=-1;
                }
               // else cout<<pow(2,i)<<" "<<as[j]<<endl;
             }
             asum+=(1ll*1)<<i;
            // cout<<i<<" "<<tsum<< " "<<pow(2,i)<<endl<<endl;
        }

    }
    printf("%lld\n",asum);
}