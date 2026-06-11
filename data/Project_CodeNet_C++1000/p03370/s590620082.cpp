#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, x;
  cin >> n >> x;
  vector<int> m(n);
  int used = 0;
  for(int i = 0; i < n; i++){
    cin >> m[i];
    used += m[i];
  }
  int left = x - used;
  int min = 100000;
  for(int i = 0; i < n; i++){
    if(min > m[i]){
      min = m[i];
    }
  }
  cout << n + left / min << endl;
  return 0;
}