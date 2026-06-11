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
  ll a[3],b[3],v[5]={};
  for(int i=0;i<3;i++){
    cin >> a[i] >> b[i];
    v[a[i]]++;
    v[b[i]]++;
  }
  for(int i=1;i<=4;i++){
    if(v[i]>=3){
      cout <<"NO\n";
      return 0;
    }
  }
  cout <<"YES\n";
}
