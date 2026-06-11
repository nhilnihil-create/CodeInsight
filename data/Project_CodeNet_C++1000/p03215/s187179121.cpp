#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

typedef long long ll;
vector<ll> A;
vector<ll> nxt;
ll sum[1005];
ll tmp;
int main() {
  int n,k;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    sum[i+1] = sum[i] + a;
  }
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j <= n; j++) {
      A.push_back(sum[j] - sum[i]);
      tmp = max(tmp,sum[j] - sum[i]);
    }
  }

  // sort(A.begin(),A.end(),greater<ll> ());
  
  /*  for(int i = 0; i < A.size(); i++) {
   
    }*/
  

  int K = 0;
  while(tmp > 0) {
    tmp /=2;
    K++;
  }


 
  ll ans = 0;
  for(int i = K - 1; i >= 0; i--) {
    ll s = (1ll << i);
    int kk = 0;
    for(int j = 0; j < A.size(); j++) {
    
      if(A[j] & s) {
	kk++;
	nxt.push_back(A[j]);
      }
    }
    // cout << s <<"   "<<kk <<"  "<<nxt.size()<<"  "<<A.size()<< endl;
     if(kk >= k) {
       ans += s;
      swap(nxt,A);
      nxt.clear();
     }
     else nxt.clear();
  }

  cout << ans << endl;
}
