#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n, k; cin >> n >> k;
  int count = 0;
  int count1 = 0;
  for(int i = 1; i < n + 1; ++i){
    if(k%2 == 1 && i%k == 0) count++;
    else if(k%2 == 0 && i%k == 0) count++;
    else if(k%2 == 0 && i%k == (k/2)) count1++;
  }
  if(k%2 == 1){
    cout << (ll)count*(ll)count*(ll)count << '\n'; 
  }
  else{
    ll ans = (ll)count*(ll)count*(ll)count;
    ans += (ll)count1*(ll)count1*(ll)count1;
    cout << ans << '\n';
  }
}