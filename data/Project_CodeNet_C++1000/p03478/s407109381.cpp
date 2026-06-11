#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int f(int n){
  int tmp = 0;
  while(n>0){
    tmp += n%10;
    n = n/10;
  }
  return tmp;
}
int main(){
  int n, a, b;
  int cnt = 0;
  cin >> n >> a >> b;
  for(int i=1; i<=n; ++i){
    if(f(i)>=a && f(i)<=b) cnt +=i;
  }

  cout << cnt;
  return 0;
}