#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,s,n) for(int i=s;i<n;i++)
typedef long long int ll;
typedef pair<int, int> P;
typedef long double ld;
void ans(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}

const ll INF=1001001001;
const ll mod=10000000007;

int main(){
  ll x,y;cin>>x>>y;
  ll z=y/x;
  ll ans=0;
  while(z>=1){
    ans++;
    z/=2;
  }
  cout<<ans<<endl;
}