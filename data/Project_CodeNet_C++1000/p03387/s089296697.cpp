#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  
  vector<int> abc(3);
    abc[0]=a;
    abc[1]=b;
    abc[2]=c;
 
  sort(abc.begin(), abc.end());
  
  int num=0;
  int d=(abc[1]-abc[0])/2;
  
  if((abc[1]-abc[0])%2==1){
    num = num + 2;
  }
  
  num = num + d;
  
  int e=abc[2]-abc[1];
  
  num = num + e;
  
  cout << num << endl;
  
}