#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int64_t m=2,o=1;
  for(int i=0;i<n;i++){
    o+=m;
    m=o-m;
  }
  cout << m << endl;
}