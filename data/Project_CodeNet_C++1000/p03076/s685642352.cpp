#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int x[5];
  int num=0, sum = 0;
  for(int i=0; i<5; ++i) cin >> x[i];

  for(int i=0; i<5; ++i){
    if((10-(x[i]%10))>num){
      if(x[i]%10==0) continue;
      num = max(num, (10-(x[i]%10)));
    }
  }

  for(int i=0; i<5; ++i){
    if(x[i]%10==0) sum += x[i];
    else sum+= x[i] + (10-(x[i]%10));
  }

  cout << sum - num;
  return 0;
}