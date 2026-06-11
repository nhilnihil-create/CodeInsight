/**
n,m=map(int,input().split())
yakusuu=[]
for i in range(1,int(m**0.5)+1):
  if m%i==0:
    yakusuu.append(m//i)
    if m//i==i:continue
    yakusuu.append(i)
ans=0
for y in yakusuu:
  if y<n:continue
  if m%y==0:
    ans=max(ans,m//y)
print(ans)
**/

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n,m;
  cin >> n >> m;
  vector<ll> yakusuu;
  for (ll i=1;i*i<=(m);i++){
    if (m%i==0) yakusuu.push_back(i);
    if (i!=m/i) yakusuu.push_back((ll)m/i);
  }
  int ans =0;
  for(ll y:yakusuu){
    if(y<n) continue;
    if(m%y==0){
      if(m/y>ans) ans=m/y;
    }
  }
  cout<<ans<<endl;
  return 0;
}

