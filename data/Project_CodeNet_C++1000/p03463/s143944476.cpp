#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n, a, b; cin >> n >> a >> b;
  string out = "Borys";
  if((b - a) % 2 == 0) out = "Alice";
  cout << out;
}
