#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  double n,m,d;
  cin>>n>>m>>d;
  double ans=(n-d)*2*(m-1)/n/n;
  if(d==0) ans/=2;
  printf("%.10f\n",ans);
}