#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int d, n;
  cin >> d >> n;

  if(n==100) n++;
  if(d==0) cout << n << endl;
  if(d==1) cout << 100*n << endl;
  if(d==2) cout << 10000*n << endl;
}