#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n, m; cin >> n >> m;
  double x = (n-m)*100+1900*m;
  
  double p = pow(0.5, m);
  cout << x/p << endl;


}
