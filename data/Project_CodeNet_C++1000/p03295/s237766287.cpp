#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,m,a,b,ans=0;cin>>n>>m;
  vector<P> v(m);rep(i,m) {cin>>a>>b;v[i]=P(b,a);}
  sort(ALL(v));
  ll cut=-1;
  for(P p:v) {
    a=p.second,b=p.first;
    if(cut<0) {cut=b-1;ans++;continue;}
    if(a<=cut) continue; 
    cut=b-1,ans++;
  }
  print(ans);
  return 0;
}