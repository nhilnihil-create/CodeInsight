#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int d,n;
  cin>>d>>n;
  int a=1;
  rep(i,0,d) a*=100;
  if(n<100) cout<<n*a;
  else cout<<101*a;
}