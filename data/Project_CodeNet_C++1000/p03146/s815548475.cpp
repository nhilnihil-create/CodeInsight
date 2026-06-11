#include <bits/stdc++.h>
using namespace std;

int f(int n){
  
  if(n%2==0) return n/2;
  
  return 3*n+1;
}

int main(){
  int s;
  cin >> s;
  
  int a = s;
  
  int index = 2;
  map<int, int> mp;
  while (mp[f(a)]==0){
    mp[a]++;
    a = f(a);
    index++;
  }
  
  cout << index << endl;
  
  return 0;
}