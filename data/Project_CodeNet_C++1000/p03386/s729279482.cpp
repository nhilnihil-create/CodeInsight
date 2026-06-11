#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  ll a,b,k;
  cin >> a >> b >> k;
  
  int x[k*2];
  int c = 0;
  for(int i = a; i <= b; i++){
    if(i < a+k || b-k < i){
      cout << i << endl;
    }
  }
  
}