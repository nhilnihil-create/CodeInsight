#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  int a,b;
  cin>>a>>b;
  if(a<=12) b/=2;
  if(a<=5) b=0;
  cout<<b<<endl;
}