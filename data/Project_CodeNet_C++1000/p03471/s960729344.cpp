#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll gcd(int a,int b){if(a%b==0){return b;}else{return(gcd(b,a%b));}}
ll lcm(int a,int b){return a*b/gcd(a,b);}
const int INF=1e9;
const ll INFS=1e18;
const int MOD=INF+7;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
const double PI=acos(-1);

int main() {
  int n,y;
  cin>>n>>y;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n-i;j++){
      if(i*10000+j*5000+(n-i-j)*1000==y){
        cout<<i<<" "<<j<<" "<<(n-i-j)<<endl;
        return 0;
      }
    }
  }
  cout<<"-1 -1 -1"<<endl;
}