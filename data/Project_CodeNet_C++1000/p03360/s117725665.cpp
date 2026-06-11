#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int a,b,c,k;
  cin>>a>>b>>c>>k;
  int d=max(a,max(b,c));
  int e=d;
  rep(i,0,k) e*=2;
  cout<<a+b+c-d+e<<endl;
}