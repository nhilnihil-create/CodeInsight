#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define vvi vector<vi>
#define DBG_N(hoge) cerr<<"!"<<" "<<(hoge)<<endl;
#define DBG cerr<<"!"<<endl;
#define BITLE(n) (1LL<<((ll)n))
#define BITCNT(n) (__builtin_popcountll(n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;cin>>n;
  vi A(n);
  for(auto &a:A)cin>>a;
  sort(ALL(A),greater<ll>());
  ll mi=llINF;
  ll ans;
  for(int i=1;i<n;i++){
    if(mi>abs(A[i]-(A[0]-A[0]/2))){
      mi=abs(A[i]-(A[0]-A[0]/2));
      ans=A[i];
    }
  }
  cout<<A[0]<<" "<<ans<<endl;
  return 0;
}
