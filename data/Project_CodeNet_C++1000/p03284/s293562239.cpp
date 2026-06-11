#include <bits/stdc++.h>
using namespace std;

int n, k;

int execute(int n, int k){
  return n % k == 0? 0 : 1;
}

int main(){
  cin >> n >> k;
  cout << execute(n, k);
}
