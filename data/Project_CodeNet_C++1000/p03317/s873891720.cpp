#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n, k; cin >> n >> k;
  int x = (n - k)%(k - 1) == 0 ? 0 : 1;
  cout << (n - k > 0 ? ((n - k)/(k - 1)) + 1 + x : 1 )<< '\n';
}