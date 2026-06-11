#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int r, d, x;
  cin >> r >> d >> x;

  ll x_ans;
  for(int i=0; i<10; ++i){
    if(i==0){
      x_ans = r * x - d;
      cout << x_ans << endl;
    }
    else{
      x_ans = r * x_ans - d;
      cout << x_ans << endl;
    }
  }
}