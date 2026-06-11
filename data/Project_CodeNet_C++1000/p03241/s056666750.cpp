#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  for(int i=m/n; i>=1; --i){
    if(m%i == 0){
      cout << i << endl;
      return 0;
    }
  }
}