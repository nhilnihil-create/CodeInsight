#include<bits/stdc++.h> 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;


int main(){
  ll a,b,c,k;
  cin >> a >> b >> c >> k;
  if( k%2 == 1 ){
    cout << b-a << endl;
  }else{
    cout << a-b << endl;
  }
  return 0;
}
