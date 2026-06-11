#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int dis(int x){ 
  return x%=10;
}

int main(){
  int x[5];
  for(int i=0; i<5; ++i) cin >> x[i];
  int mn = 10, cnt = 0;
  for(int i=0; i<5; ++i){
    if(x[i]%10==0) continue;
    if(mn>dis(x[i])){
      mn = min(mn, dis(x[i]));
    }
  }
  for(int i=0; i<5; ++i){
    if(x[i]%10==0) cnt+=x[i];
    else cnt += x[i] + abs(10-dis(x[i]));
  }

  cout << cnt - abs(10-mn) << endl;
  return 0;
}