#include<bits/stdc++.h>
using namespace std;

int sum(int x){
  int s = 0;
  while(x > 0){
    s += x % 10;
    x /= 10;
  }
  return s;
}

int main(){
  int n; cin >> n;
  
  int m = 1000000;
  for(int i = 1; i < n; i++){
    int a = i; int b = n-i;
    if(sum(a) + sum(b) < m) m = sum(a) + sum(b);
  }
  cout << m << endl;
}