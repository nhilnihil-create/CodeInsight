#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,s,n) for(int i=s;i<n;i++)
#define fi first
#define se second
#define all(c) c.begin(),c.end()
typedef long long int ll;
typedef pair<int, int> P;
typedef long double ld;
void Ans(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}

const int INF=100100;
const ll mod=1000000007;

int main(){
  int n;cin>>n;
  vector<P> a(n),b(n);
  int q,w;
  rep(i,n){
    cin>>q>>w;
    a[i]=P(w,q);
  }
  rep(i,n){
    cin>>q>>w;
    b[i]=P(q,w);
  }
  sort(all(b));
  sort(all(a));
  int ans=0;
  rep(i,n){
    P now=b[i];
    int d=-1;
    rep(j,n){
      if(now.fi>a[j].se&&now.se>a[j].fi){
        d=max(d,j);
      }
    }
    if(d!=-1){
      ans++;
      a[d]=P(INF,INF);
    }
  }
  
  cout<<ans<<endl;
}