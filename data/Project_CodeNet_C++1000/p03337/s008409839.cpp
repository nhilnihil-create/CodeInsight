#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin >>a>>b;
  int saidai;
  saidai = a+b;
  saidai = max(saidai,a-b);
  saidai = max(saidai,a*b);
  
  cout << saidai << endl;

}
