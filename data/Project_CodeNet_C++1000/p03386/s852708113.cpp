#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int a, b, k;
  cin >> a >> b >> k;
  if(2*k>b-a+1){
    for(int i=a; i<=b; ++i) cout << i << endl;
    return 0;
  }

  for(int i=a; i<=a+k-1; ++i){
    cout << i << endl;
  }
  for(int i=b-k+1; i<=b; ++i){
    cout << i << endl;
  }
}