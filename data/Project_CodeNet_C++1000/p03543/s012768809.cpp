#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A;
  cin >> A;
  
  int o, p, q, r;
  int w, x;
  o = A / 1000; 	//千の位
  w = A - 1000 * o;	//A - 千の位
  p = w / 100;		//百の位
  x = w - 100 * p;	//A - 千の位 - 百の位
  q = x / 10;		//十の位
  r = x - 10 * q;	//一の位
  
  if (p == q){
    if(o == p || q == r){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
  	}
  }else{
      cout << "No" << endl;
  }
}