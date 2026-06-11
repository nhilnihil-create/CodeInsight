#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  for(int i=0; i<n; ++i) cin >> a[i];

  int cnt = 0;
  for(int i=0; i<n; ++i){
    while(a[i]%2==0){
      a[i]/=2;
      cnt++;
    }
  }
  cout << cnt << endl;

}