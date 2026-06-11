#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define  boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define d1(x) cout<<#x<<" "<<x<<endl;
#define d2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define d2i(x,y,i) cout<<#x<<i<<" "<<x<<" "<<#y<<i<<" "<<y<<endl;

#define fr(i,l,r) for(ll i=l;i<r;i++)
#define mems(a,x) memset(a,x,sizeof(a))
#define mod 1000000007
#define ff first
#define ss second
#define pb(x) push_back(x)
#define vll vector<ll>
#define pbp(x,y) push_back(make_pair(x,y))
#define  mat vector<vector<ll>>
#define all(v) v.begin(),v.end()
///////////////////////////////////////////
void solve(){
  ll n;
  cin>>n;
  const ll N=55556;
  bool p[N+1];
  mems(p,true);
  for( ll i=2;i*i<N;i++){
      if(p[i]){
        for(ll j=i*i;j<N;j+=i){
              p[j]=false;
        }
      }
  }
  vll ans;
  fr(i,2,N){
    if(p[i] && i%5==1){
    ans.pb(i);       
    }
    if(ans.size()==n)
    break;
  }
  for(ll &x:ans){
    cout<<x<<" ";
  }

}




int main(){
    ll t=1;
 // cin>>t;
  ll f=1;
    while(f<=t){
      //  cout<<"Case #"<<f<<": ";
        solve();
        cout<<endl;
        f++;
    }
    return 0;
}