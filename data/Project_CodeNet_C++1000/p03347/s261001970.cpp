#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll> 
#define ALL(a) (a).begin(),(a).end()
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,ans=0;cin>>n;
  bool isok=false;
  lvector A(n,0);rep(i,n) cin>>A[i];
  if(A[0]==0) {
    ll pos=0;
    while(pos<n-1) {
      ll prev=A[pos],next=A[pos+1];
      if(prev+1<next) break;
      else if(prev+1==next) ans++;
      else ans+=next;
      pos++;
    }
    if(pos==n-1) isok=true;
  }
  if(isok) print(ans);else print(-1);
  return 0;
}