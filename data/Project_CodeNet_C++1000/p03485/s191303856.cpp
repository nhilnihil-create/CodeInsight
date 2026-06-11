#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin >> a >> b;
  if((a%2==0 && b%2==0 ) ||(a%2==1 && b%2==1))cout << (a+b)/2 << endl;
  else cout << 1+(a+b)/2 << endl;
}