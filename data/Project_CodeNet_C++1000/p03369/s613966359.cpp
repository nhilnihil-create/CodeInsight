#include <bits/stdc++.h>
using namespace std;

int main() {
  int R = 700;
  string s;
  cin >>s;
    
  int topping;
  
  if(s[0]=='o')++topping;
  if(s[1]=='o')++topping;
  if(s[2]=='o')++topping;
 
  int kingaku = R+(topping*100);
  cout<<kingaku<<endl;
}