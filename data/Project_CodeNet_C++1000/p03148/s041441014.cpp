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
const int inf=100000000000007;
const int MOD=1000000007;
signed main(){
  int n,k;cin>>n>>k;
  int del=0;int spe=0;int sum=0;
  vector<pair<int,int>> susi(n);
  rep(i,n){
    cin>>susi[i].second>>susi[i].first;
  }
  sort(ALL(susi));
  reverse(ALL(susi));
  vector<int> neta(n+2,0);
  vector<int> kaburi;
  rep(i,k){
    del+=susi[i].first;
    if(neta[susi[i].second]==0){
      neta[susi[i].second]++;
      spe++;
    }
    else{
      kaburi.push_back(susi[i].first);
    }
  }
  reverse(ALL(kaburi));
  kaburi.push_back(inf);
  susi.push_back(make_pair(0,0));
  int p=0;
  sum=del+spe*spe;
  int j=k;
  for(int i=spe+1;i<=k;i++){
    while(neta[susi[j].second]!=0){
      j++;
    }
    if(j>=n)break;
    if(kaburi[p]==inf)break;
    del-=kaburi[p];
    p++;
    del+=susi[j].first;
    neta[susi[j].second]++;
    spe++;
    sum=max(sum,del+i*i);
  }
  cout<<sum<<endl;
  return 0;
}
