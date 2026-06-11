#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  ll m = 0, ans = 0;
  for(int i=0; i<n; ++i) cin >> a[i];

  for(int i=0; i<n; ++i){
    ans += a[i]-1;
  }

  cout << ans << endl;
}