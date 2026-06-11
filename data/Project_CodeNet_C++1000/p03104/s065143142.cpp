#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll xo(ll x,ll res){
  if(x==-1){
    return 0;
  }
  ll sum=0;
  x++;
  sum+=x/res*(res/2);
  x=x%res;
  sum+=max((ll)0,x-res/2);
  return sum;
}
int main(){
  ll a,b;
  cin >> a >> b;
  ll ans=0;
  ll res=2;
  for(int i=0;res<=b*2;i++){
    if((xo(b,res)-xo(a-1,res))%2==1){
      ans=ans|(ll)pow(2,i);
    }
    res*=2;
  }
  cout << ans << endl;
}