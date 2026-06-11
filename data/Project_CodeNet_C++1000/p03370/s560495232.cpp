#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, x;
  cin >> n >> x;
  vector<int> m(n);
  int M = x;
  int min = 1001;
  int a = 0;
  int i = 0;
  
  for(int i = 0; i<n; i++){
    cin >> m.at(i);
    M -= m.at(i);
    if(m.at(i) < min)
      min = m.at(i);
  }
  
  while(a <= M){
    i++;
    a = min*i;
  }
  
  cout << i - 1 + n << endl;
}