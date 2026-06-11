#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; ++i) cin >> a[i];

  int num = 1, num1 = 1;
  for(int i=0; i<n; ++i){
    num *=  3;
    if(a[i]%2 == 0) num1 *= 2;
  }

  cout << num - num1 << endl;
}