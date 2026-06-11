#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main(void){
    int x; cin >> x;
  ll ans = 0;
  for(ll b = 1; b <= 100; b++){
    ll num = b;
  	for(int p = 2; p <= 10; p++){
    	num *= b;
      	if(num <= x){
        	ans = max(num, ans);
        }
    }
  }
  cout << ans << endl;
    return 0;
}