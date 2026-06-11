#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n;
  cin >> n;
  
  vector<ll> L(100);
  L[0]=2;
  L[1]=1;
  
  for (int i = 2; i < 90; i++){
    L[i] = L[i-1] + L[i-2]; 
  }
  
  if(n==1){
    cout << 1 << endl;
  }else{
    cout << L[n] << endl;
  }

  return 0;
}