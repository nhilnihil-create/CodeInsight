#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

int main() {
  ll n;
  cin>>n;
  if(n<=9){
    cout<<n<<endl;
    return 0;
  }
  ll digit=0;
  ll d;
  bool ans[20];
  for(int i=0;i<20;i++) ans[i]=true;
  int a=0;
  while (n>0){
    d=n%10;
    n/=10;
    digit++;
    if(d!=9) ans[a]=false;
    a++;
  }
  for(int i=0;i<digit-1;i++){
    if(!ans[i]) ans[19]=false;
  }
  if(ans[19]) cout<<d+(digit-1)*9<<endl;
  else cout<<d-1+(digit-1)*9<<endl;
  return 0;
}
