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

const ll INF=1001001001;
const ll mod=1000000007;

int main(){
  int n,m;cin>>n>>m;
  int a,b;
  vector<P> v(m);
  rep(i,m){
    cin>>a>>b;
    if(a<b){
      v[i]=P(b,a);
    }
    else{
      v[i]=P(a,b);
    }
  }
  
  sort(all(v));
  int now=v[0].fi;
  int ans=1;
  rep(i,m){
    if(v[i].fi!=now&&now<=v[i].se){
      ans++;
      //cout<<now<<endl;
      now=v[i].fi;
      
    }
  }
  
  cout<<ans<<endl;
}