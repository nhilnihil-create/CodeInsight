#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k; cin >> n >> k;
  int idx;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    if(a == 1) idx = i;
  }
  cout << (n-2)/(k-1) + 1 << endl;
}

