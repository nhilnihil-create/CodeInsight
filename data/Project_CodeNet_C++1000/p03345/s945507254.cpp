#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define rep(i,n) for(int i = 0; i< n; i++);

int main() {
  ll  a , b , c , k ;
  cin >> a >> b >> c >> k ;
  
  if(k%2==1){
  cout << b-a << endl;
  }
  
  else {
  cout << a-b << endl;
  }
}

