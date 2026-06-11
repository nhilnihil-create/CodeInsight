#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<=n;++i)
bool cs(pair<int,int> a,pair<int,int> b){
  if(a.second==b.second)return a.first>b.first;
  else return a.second>b.second;
}
int main(){
  int n;cin>>n;
  vector<int> a(n);
  vector<int> b(n);
  rep(i,n)cin>>a[i]>>b[i];
  vector<pair<int,int>> sum(n);
  rep(i,n){
    sum[i].second=a[i]+b[i];
    sum[i].first=i;
  }
  sort(sum.begin(),sum.end(),cs);
  //  rep(i,n)cout<<sum[i].second<<endl;
  ll sa=0;ll sb=0;
  rep(i,n){
    if(i%2==0)sa+=a[sum[i].first];
    else sb+=b[sum[i].first];
  }
  cout<<sa-sb<<endl;
  return 0;
}
