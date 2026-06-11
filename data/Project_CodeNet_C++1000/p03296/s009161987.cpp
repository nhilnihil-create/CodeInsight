#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll n,cnt=0;
  cin >> n;
  ll a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=1;i<n;i++){
    if(a[i]==a[i-1]){
      cnt++;
      i++;
    }
  }
  cout << cnt << endl;
}
