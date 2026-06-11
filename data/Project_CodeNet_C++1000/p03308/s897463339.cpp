#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main(void){
    int n; cin >> n;
  vector<ll> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  
  ll ans = 0;
  for(int i=0; i<n; i++){
  	for(int j=0; j<n; j++){
    	if(ans < abs(a[i] - a[j])) ans = abs(a[i] - a[j]);
    }
  }
  cout << ans << endl;
    return 0;
}