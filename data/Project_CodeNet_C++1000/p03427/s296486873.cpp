#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int keta(ll n){
  ll tmp=0;
  while(n>0){
    tmp += n%10;
    n = n/10;
  }
  return tmp;
}

int main(){
  ll n;
  cin >> n;
  n++;
  string sn = to_string(n);
  char c = sn[0];
  int first = c - '0';

  int size = sn.size();

  int ans = 9*(size-1) +  first-1;

  cout << ans;

}