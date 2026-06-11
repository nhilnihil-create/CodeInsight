#include "bits/stdc++.h"
using namespace std;

#define int long long
#define mp make_pair

int aa[1005],bb[1005],cc[1005];

vector<int> v;

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int a,b,c,k,lo,hi,mid,cnt,cnt2;//should have k-1 numbers less than the answer...
    cin>>a>>b>>c>>k;
    for(int x=0;x<a;x++)cin>>aa[x];
    for(int x=0;x<b;x++)cin>>bb[x];
    for(int x=0;x<c;x++)cin>>cc[x];
    for(int x=0;x<a;x++){
      for(int y=0;y<b;y++){
        v.push_back(aa[x]+bb[y]);
      }
    }
    sort(v.begin(),v.end());
    priority_queue<pair<int,pair<int,int> > > pq;
    //the next number, cc[x], next iterator in v...
    for(int x=0;x<c;x++){
      pq.push(mp(cc[x]+v.back(),mp(cc[x],v.size()-1)));
    }
    pair<int,pair<int,int> > pp;
    for(int x=0;x<k;x++){
      cout<<pq.top().first<<'\n';
      pp=pq.top();
      pq.pop();
      if(pp.second.second==0)continue;
      pp.second.second--;
      pp.first=pp.second.first+v[pp.second.second];
      pq.push(pp);
    }
    return 0;
}
