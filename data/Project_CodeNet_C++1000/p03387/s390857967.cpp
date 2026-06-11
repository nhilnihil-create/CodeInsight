#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  if(a > b) swap(a,b);
  if(b < c) swap(b,c);
  int ab = b-a;
  int bc = b-c;
  if((ab + bc)%2 == 0){
    cout << (ab+bc)/2 << endl;
  }else{
    cout << (ab+bc+3)/2 << endl;
  }
}