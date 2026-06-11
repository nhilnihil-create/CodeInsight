// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll a,b,k,t0,t1;
  cin >> a >> b >> k;
  for(int i=0;i<k;i++){
    if(i%2==0){
      if(a%2==1){
        a--;
      }
      t0= a/2;
      a/=2;
      b+=t0;
    }else{
      if(b%2==1){
        b--;
      }
      t1 = b/2;
      b/=2;
      a+=t1;
    }
  }
  cout << a<<" "<<b<<endl;
}
