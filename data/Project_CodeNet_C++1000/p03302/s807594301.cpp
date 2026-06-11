#include<bits/stdc++.h>
using namespace std;
int main(void){
  int a,b,c;
  string s;
 cin >> a >> b;
  if(a + b == 15){
    cout << '+';
  }else if(a * b == 15){
    cout << '*';
  }else{
    cout << 'x';
  }
}