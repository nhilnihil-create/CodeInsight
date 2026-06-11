#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
const int INF = 1001001001;
const ll mod = 1e9+7;

int main() {
  ll n,k;
  cin>>n>>k;
//  map <ll,ll> mp;
  vector<vector<ll>> v(n);// <d,t>


  rep(i,n){
    ll t1,d1;
    cin>>t1>>d1;
    t1--;
    v[t1].push_back(d1);

    //if (mp[t1]<d1) mp[t1]=d1;
  }
  std::priority_queue<ll, std::vector<ll>, std::greater<ll> > pq;
  priority_queue<ll>pq1;
  priority_queue<ll>pq2;

ll ans=0;
ll sm=0;
 rep(i,n){
   v[i].push_back(-INF);

    // kind++;
     sort(v[i].rbegin(),v[i].rend());
     pq2.push(v[i][0]);
    // sm+=v[i][0];
     rep(j,v[i].size()-1){
       pq1.push(v[i][j+1]);
     }
 }
rep(i,n){
  ll now=pq2.top();
  pq2.pop();
  if(i<k){
    sm+=now;
    pq.push(now);
  }
  else pq1.push(now);
}
ans=sm+k*k;
 rep(i,k){
//   cout<<sm<<' '<<ans<<endl;

   ll n1=pq.top();
   pq.pop();
   ll n2=pq1.top();
//   cout<<n1<<' '<<n2<<endl;
   pq1.pop();
   sm-=n1;
   sm+=n2;
   if (n1>=n2)break;
   ans=max(ans,sm+(k-i-1)*(k-i-1));

 }

   cout<<ans;


}
