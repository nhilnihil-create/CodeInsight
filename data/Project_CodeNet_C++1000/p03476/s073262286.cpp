#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n=100000;
  vector<bool> prime(100005,true);
  for(int i=2; i<=n; ++i){
    if(!prime[i]) continue;
    for(ll j=(ll)i*i; j<=n; j += i){
      prime[j] = false;
    }
  }
  vector<int> near2017(0);
  for(int i=3; i<=n; i+=2){
    if(prime[i] && prime[(i+1)/2]) near2017.push_back(i);
  }
  int q;
  cin >> q;
  for(int i=0; i<q; ++i){
    int l, r;
    cin >> l >> r;
    auto itl = lower_bound(near2017.begin(),near2017.end(),l);
    auto itr = upper_bound(near2017.begin(),near2017.end(),r);
    cout << itr - itl << endl;
  }
}