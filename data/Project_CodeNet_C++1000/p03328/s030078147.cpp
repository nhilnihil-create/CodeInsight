#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin >> a >> b;
  vector <int> h(1000,0);
    for (int i=1 ; i<1000;i++){
      h.at(i) = h.at(i-1)+i ;
    }
  cout << h.at(b-a)-b << endl;
}