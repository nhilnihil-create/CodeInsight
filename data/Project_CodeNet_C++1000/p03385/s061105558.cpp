#include<iostream>
using namespace std;
int main(){
  int a[10000] = {};
  for(int i = 0; i < 3; ++i){
    char c; cin >> c;
    a[c]++;
  }
  cout << (a['a']&&a['b']&&a['c'] ? "Yes" : "No") << endl;
}