#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n;cin >> n;
  vector<int> v(n), c(n);
  for(int i=0; i<n; ++i) cin >> v[i];
  for(int i=0; i<n; ++i) cin >> c[i];
  int X=0, Y=0;
  for(int i=0; i<n; ++i){
    if(v[i]>c[i]){
      X += v[i];
      Y += c[i];
    }
  }
  cout << X-Y << endl;
}
