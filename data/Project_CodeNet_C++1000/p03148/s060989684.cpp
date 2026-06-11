#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int n,k;cin>>n>>k;
  vector<int> t(n);
  vector<int> d(n);
  int i;
  rep(i,n)cin>>t[i]>>d[i];
  rep(i,n)t[i]--;
  vector<pair<int,int>> ps(n);
  rep(i,n)ps[i]=make_pair(d[i],t[i]);
  vector<int> pushed(n,0);
  sort(all(ps));
  reverse(all(ps));
  ll kans=0;
  priority_queue<int,vector<int>,greater<int>> pq;
  priority_queue<pair<int,int>> npick;
  rep(i,k)
  {
    if(pushed[ps[i].second]>0)
    {
      pq.push(ps[i].first);
    }
    pushed[ps[i].second]++;
    kans+=ps[i].first;
  }
  for(i=k;i<n;i++)npick.push(ps[i]);
  ll kcount=0;
  rep(i,n)if(pushed[i]>0)kcount++;
  ll ans=kans+kcount*kcount;
  while(!npick.empty()&&!pq.empty())
  {
    pair<int,int> pnum=npick.top();
    npick.pop();
    int a=pnum.first;
    int b=pnum.second;
    if(pushed[b]>0)continue;
    pushed[b]=1;
    int dnum=pq.top();
    pq.pop();
    kans=kans-dnum+a;
    kcount++;
    ll cans=kans+kcount*kcount;
    ans=max(ans,cans);
  }
  cout<<ans<<endl;
}
