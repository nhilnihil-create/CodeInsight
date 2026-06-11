#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000

int MOD=1000000007;
int modpow(int a,int x){
  if(a<0)a+=MOD;
  int ans=1;
  while(x>0){
    if(x&1) ans=ans*a%MOD;
      a=a*a%MOD;
      x>>=1;
  }
  return ans;
}

int gyaku(int n){
    return modpow(n,MOD-2);
}
////////////////////////////////////////////////////////////
signed main() {
  int n,h;
  cin>>n>>h;
  vector<int>a(n);
  vector<int>b(n);
  rep(i,n){
    cin>>a[i]>>b[i];
  }

  sort(b.begin(),b.end());
  reverse(b.begin(),b.end());
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  int i=0,damage=0,kaisuu=0;
  while(a[0]<b[i]&&i<=n-1){
    damage+=b[i];
    kaisuu++;
    if(damage>=h){
      cout<<kaisuu<<endl;
      exit(0);
    }
    i++;
  }
  cout<<kaisuu+(int)ceil((double)(h-damage)/a[0])<<endl;
}
