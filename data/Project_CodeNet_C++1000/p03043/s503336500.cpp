#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const ll INFS=1e18;
const int MOD=INF+7;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

ll choose2(ll n){
  return n*(n-1)/2;
}
 
int main(){
  double n,k;
  cin>>n>>k;
  double ans=0;
  rep(i,n){
    double tot=1/n;
    int cnt=i+1;
    while(cnt<k){
      tot/=2;
      cnt*=2;
    }
    ans+=tot;
  }
  printf("%.10f\n",ans);
}