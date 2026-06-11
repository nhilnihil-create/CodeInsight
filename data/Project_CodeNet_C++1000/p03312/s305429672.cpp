#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(){
  int n;
  cin>>n;
  vector<ll> array(n+1),sum(n+1,0);
  for(int i=1;i<=n;i++){
    cin>>array[i];
    sum[i]=sum[i-1]+array[i];
  }
  ll ans=1e12;
  for(int i=2;i<n-1;i++){
    P ls[2];
    int lps=upper_bound(sum.begin(),sum.begin()+i+1,sum[i]/2)-sum.begin();
    ls[0].first=sum[lps];
    ls[0].second=sum[i]-sum[lps];
    ls[1].first=sum[lps-1];
    ls[1].second=sum[i]-sum[lps-1];
    P rs[2];
    int rps=upper_bound(sum.begin()+i+1,sum.end(),sum[i]+(sum[n]-sum[i])/2)-sum.begin();
    rs[0].first=sum[rps]-sum[i];
    rs[0].second=sum[n]-sum[rps];
    rs[1].first=sum[rps-1]-sum[i];
    rs[1].second=sum[n]-sum[rps-1];
    ll kns=1e12;
    for(int i=0;i<2;i++){
      for(int j=0;j<2;j++){
        kns=min(kns,max({ls[i].first,ls[i].second,rs[j].first,rs[j].second})-min({ls[i].first,ls[i].second,rs[j].first,rs[j].second}));
      }
    }
    ans=min(ans,kns);
  }
  cout<<ans<<endl;
}
