#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve(){
   int n,m;
   cin >> n >> m;
   vector<int>p(m);
   vector<int>y(m);
   vector<vector<int>>v(n);
   for(int i=0;i<m;i++){
       cin >> p[i] >> y[i];
       p[i]--;
   }
   for(int i=0;i<m;i++){
       v[p[i]].push_back(y[i]);
   }
   for(int i=0;i<n;i++){
       sort(v[i].begin(),v[i].end());
   }
   for(int i=0;i<m;i++){
       printf("%06d",p[i]+1);
       int id=lower_bound(v[p[i]].begin(),v[p[i]].end(),y[i])-v[p[i]].begin();
       printf("%06d\n",id+1);
   }
}

int main(){
  solve();
  return 0;
}
