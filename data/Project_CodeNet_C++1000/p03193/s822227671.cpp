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
  ll n,h,w,cnt=0;
  cin >> n >> h >> w;
  ll a[n],b[n];
  for(int i=0;i<n;i++){
    cin >> a[i] >> b[i];
    if(a[i]>=h&&b[i]>=w){
      cnt++;
    }
  }
  cout << cnt<<endl;
}
