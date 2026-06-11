#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int  main(){
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  for(int i=0; i<n; ++i) cin >> h[i];
  sort(h.begin(), h.end());
  int mn = pow(10, 9);
  for(int i=0; i<n-k+1; i++){
    mn = min(h[i+k-1]-h[i], mn);
  }
  cout << mn; 
  return 0;
}