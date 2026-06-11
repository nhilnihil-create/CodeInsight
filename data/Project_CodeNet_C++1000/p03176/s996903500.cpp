#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll mod=1e9+7;
vector<ll>f(1<<20);
void upd(ll pos,ll val){
  for(ll i=pos;i<f.size();i+=(i&(-i)))f[i]=max(f[i],val);
}
ll q(ll pos){
  ll ma=0;
  for(ll i=pos;i>0;i-=(i&(-i)))ma=max(ma,f[i]);
  return ma;
}
ll N;
signed main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
		cin>>N;
		ll ma=0;
		vector<ll>h;
		for(int i=0;i<N;i++){
      ll a;cin>>a;
      h.push_back(a);
		}
		for(ll i=0;i<N;i++){
      ll a;
      cin>>a;
      ll k=q(h[i]-1);
      upd(h[i],k+a);
      ma=max(ma,k+a);
		}
		cout<<ma;
    return 0;
}