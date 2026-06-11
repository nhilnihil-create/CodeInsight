#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main(){
  int a,b,k;
  cin >> a >> b >> k;
  int lim = min(a,b);
  
  int n = 0;
  for(int i = lim; ;i--){
    if(a%i==0&&b%i==0) n++;
    if(n==k){
      cout << i << endl;
      return 0;
    }
  }
}