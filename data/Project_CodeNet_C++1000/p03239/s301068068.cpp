#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n, T; cin >> n >> T;
  vector<int> c(n), t(n);

  for(int i=0; i<n; ++i) cin >> c[i] >> t[i];

  int mn = 1001, cnt = 0;
  for(int i=0; i<n; ++i){
    if(t[i] <= T){
      mn = min(c[i], mn);
      cnt++;
    }
  }
  if(cnt == 0) cout << "TLE";
  else cout << mn;
}  
