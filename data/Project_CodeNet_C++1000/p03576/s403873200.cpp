#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
bool cs(P a,P b){
  if(a.second==b.second)return a.first>b.first;
  else return a.second>b.second;
}
signed main(){
  int n,K;cin>>n>>K;
  vector<P> p(n);
  int res=INT64_MAX;
  rep(i,n){
    cin>>p[i].first>>p[i].second;
  }
  //cout<<res<<"\n";
  sort(p.begin(),p.end(),cs);
  rep(i,n){
    //printf("%lld %lld\n",p[i].first,p[i].second);
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        for(int l=0;l<n;l++){
          vector<P> buf(4);
          buf[0]=p[i];
          buf[1]=p[j];
          buf[2]=p[k];
          buf[3]=p[l];
          sort(buf.begin(),buf.end());
          int left=buf[0].first;
          int right=buf[3].first;
          sort(buf.begin(),buf.end(),cs);
          int up=buf[0].second;
          int down=buf[3].second;
          int tmp=0;
          rep(i,n){
            if(p[i].first<=right&&p[i].first>=left){
              if(p[i].second<=up&&p[i].second>=down){
                tmp++;
              }
            }
          }
          if(tmp>=K){
           int s=max((int)1,(up-down))*max((int)1,(right-left));
           if(res>s){
             res=s;
             //cout<<tmp<<" k="<<k<<"\n";
             //printf("s=%lld\nleft=%lld\nright=%lld\nup=%lld\ndown=%lld\n",s,left,right,up,down);
          }
          }
        }
      }
    }
  }
  cout<<res<<"\n";
  return 0;
}
