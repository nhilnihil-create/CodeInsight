#include<bits/stdc++.h>
using namespace std;
int main(void){
  int a,b,c;
  string s;
 cin >> a >> b >> c;
  if(a < b){
    if(a < c && c < b){
      cout << "Yes";
    }else{
      cout << "No";
    }
  }else{
    if(a > c && c > b){
      cout << "Yes";
    }else{
      cout << "No";
    }
  }
}