#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n; cin >> n;
  vector<int> p(n);
  for(int i=0; i<n; ++i) cin >> p[i];

  sort(p.rbegin(), p.rend());
  int x = p[0] / 2;
  int sum = 0;
  for(int i=1; i<n; ++i){
    sum += p[i];
  }
  cout << x + sum;
}  
