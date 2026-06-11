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

const int INF=100100;
const ll mod=1000000007;

int main(){
  int n,m;
  map<string,int> map;
  string a;
  cin>>n;
  rep(i,n){
    cin>>a;
    map[a]++;
  }
  cin>>m;
  rep(i,m){
    cin>>a;
    map[a]--;
  }
  
  int ans=0;
  
  
  for(auto x:map){
    ans=max(ans,x.se);
  }
  
  cout<<ans<<endl;
}
