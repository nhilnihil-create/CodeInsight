#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  
  int N = (int)S.size();
  
  int ans = 0;
  //aとbのminを２倍する
  int a = 0;
  int b = 0;
  
  
  for(int i = 0; i < N; i++){
    if(S.at(i) == '0')a++;
    else b++;
  }
  
  cout << 2 * min(a,b) << endl;
  
  
  
}