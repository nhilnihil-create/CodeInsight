#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int64_t> l(n+1);
  l[0] = 2;
  l[1] = 1;
  for(int i = 2; i < n+1; i++){
    l[i] = l[i-1]+l[i-2];
  }
  cout << l[n] << endl;
}