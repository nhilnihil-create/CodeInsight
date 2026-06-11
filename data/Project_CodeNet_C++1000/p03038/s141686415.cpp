#include <bits/stdc++.h>
using namespace std;
#define	rep(i,n)	for(int i=0;i<(n);i++)

int main(){
  int n,m;	cin >> n >> m;
  map<long long,long long>	A;
  priority_queue<long long, vector<long long>, greater<long long>> p;
  rep(i,n){
    long long a;	cin >> a;
    A[a]++;
    p.push(a);
  }
  
  vector<pair<long long,int>>	cb(m);
  rep(i,m)	cin >> cb[i].second >> cb[i].first;
  sort(cb.rbegin(),cb.rend());
  
  rep(i,m){
    long long b=cb[i].second;
    long long c=cb[i].first;
    while(b>0){
      long long now=p.top();
      if(now>=c)	break;
      long long x=min(A[now],b);
      A[now]-=x;
      A[c]+=x;
      b-=x;
      p.push(c);
      if(A[now]==0){
        A.erase(now);
        p.pop();
      }
    }
  }
  
  long long ans=0;
  for(auto q:A){
    ans+=q.first*q.second;
  }
  cout << ans;
}