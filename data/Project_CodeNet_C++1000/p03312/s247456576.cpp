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
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
using P=pair<int,int>;
using lint=long long;
using ll=long long;
const lint inf=1e18+7;
const int MOD=1000000007;
signed main(){
  int n;cin>>n;
  vector<int> a(n);
  rep(i,n)cin>>a[i];
  vector<int> sum(n+2,0);
  rep1(i,n){
    sum[i]=sum[i-1]+a[i-1];
  }
  int res=inf;
  sum[n+1]=inf;
  for(int i=2;i<n-1;++i){
    int f_sum=sum[i];
    int r_sum=sum[n]-sum[i];
    int f_half=f_sum/2;
    int r_half=r_sum/2;
    auto f_it=lower_bound(sum.begin(),sum.begin()+i+1,f_half);
    auto r_it=lower_bound(sum.begin()+i+1,sum.end(),r_half+f_sum);

    //printf("i = %lld, f_sum = %lld, f_it = %lld, r_sum = %lld, r_it = %lld\n",i,f_sum,*f_it,r_sum,*r_it);
    vector<int> buf(4);
    buf[0]=*f_it;buf[1]=*r_it-f_sum;buf[2]=f_sum-*f_it;buf[3]=r_sum-*r_it+f_sum;
    sort(buf.begin(),buf.end());
    res=min(res,buf[3]-buf[0]);
    --f_it;
    //printf("i = %lld, f_sum = %lld, f_it = %lld, r_sum = %lld, r_it = %lld\n",i,f_sum,*f_it,r_sum,*r_it);
    buf[0]=*f_it;buf[1]=*r_it-f_sum;buf[2]=f_sum-*f_it;buf[3]=r_sum-*r_it+f_sum;
    sort(buf.begin(),buf.end());
    res=min(res,buf[3]-buf[0]);
    --r_it;
    //printf("i = %lld, f_sum = %lld, f_it = %lld, r_sum = %lld, r_it = %lld\n",i,f_sum,*f_it,r_sum,*r_it);
    buf[0]=*f_it;buf[1]=*r_it-f_sum;buf[2]=f_sum-*f_it;buf[3]=r_sum-*r_it+f_sum;
    sort(buf.begin(),buf.end());
    res=min(res,buf[3]-buf[0]);
    ++f_it;
    //printf("i = %lld, f_sum = %lld, f_it = %lld, r_sum = %lld, r_it = %lld\n",i,f_sum,*f_it,r_sum,*r_it);
    buf[0]=*f_it;buf[1]=*r_it-f_sum;buf[2]=f_sum-*f_it;buf[3]=r_sum-*r_it+f_sum;
    sort(buf.begin(),buf.end());
    res=min(res,buf[3]-buf[0]);
  }
  cout<<res<<"\n";
  return 0;
}
