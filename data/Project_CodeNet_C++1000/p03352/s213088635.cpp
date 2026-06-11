#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int x;
  cin >> x;
  
  int res[5000];
  for(int i=0 ; i<5000; ++i) res[i] = 1;

  int a=0;
  for(int i=1; i<=x; ++i){
    for(int j=2; j<=x; ++j){
      int num = pow(i,j);
      if(num > x) break;
      res[a] = num;
      a++;
    }
  }
  int mx = 0;
  for(int i=0; i<5000; ++i){
    mx = max(res[i], mx);
  }
  cout << mx;
}