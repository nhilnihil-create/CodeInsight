#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b;
  cin >> a >>b;
  for(int i=1;i<=a;i+=2){
    b--;
  }
  cout << (b<=0? "YES":"NO")<<endl;
}