#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  cout<<min(a,b)+min(c,d)<<endl;
}