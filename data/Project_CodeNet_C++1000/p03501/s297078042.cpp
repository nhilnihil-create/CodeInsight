#include <bits/stdc++.h>
using namespace std;

int n,a,b;
int main() {
  cin >> n >> a >> b;
  
  int plan1 = n * a;
  int plan2 = b;
  
  cout << (plan1>plan2 ? plan2:plan1)  << endl;
}