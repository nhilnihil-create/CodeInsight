#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,s,n) for(int i=s;i<n;i++)
#define per(i,s,n) for(int i=n-1;i>=s;i--)
#define fi first
#define se second
#define all(c) c.begin(),c.end()
typedef long long int ll;
typedef pair<int, int> P;
typedef long double ld;
void Ans(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}

const ll INF=1001001001;
const ll mod=1000000007;

int main(){
  int n,m,c;
  cin>>n>>m>>c;
  int a[m];
  int b[m];
  rep(i,m) cin>>b[i];
  int ans=0;
  rep(i,n){
    int d=0;
    rep(j,m){
      cin>>a[j];
      d+=a[j]*b[j];
    }
    d+=c;
    if(d>0) ans++;
  }
  
  cout<<ans<<endl;
}

