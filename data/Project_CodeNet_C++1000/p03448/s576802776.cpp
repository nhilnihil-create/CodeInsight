#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  int cnt =0;
  for(int i=0; i<=a; ++i){
    for(int j=0; j<=b; ++j){
      for(int k=0; k<=c; ++k){
        if(i*500 + j*100 + k*50 == x) cnt++;
      }
    }
  }

  cout << cnt << endl;

  return 0;
}