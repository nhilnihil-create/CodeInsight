#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll a,b,k;
  cin >> a >> b >> k;
  for(int i=0;i<k;i++){
    if(i%2==0){
      b+=a/2;
      a/=2;
    }else{
      a+=b/2;
      b/=2;
    }
  }
  cout << a<<" "<<b<<endl;
}
