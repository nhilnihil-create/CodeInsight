#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  ll a, b, c;
  ll k;
  cin >> a >> b >> c >> k;
  
  if(k%2==0){
    cout << a-b << endl;
    return 0;
  }
  cout << b-a << endl;

  return 0;
}