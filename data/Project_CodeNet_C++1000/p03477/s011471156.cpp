#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,c,d;
  
  cin >> a >> b >> c >> d;
  if(a + b == c + d){
    cout << "Balanced";
  }
  else if(a + b > c + d){
    cout << "Left";
  }
  else{
    cout << "Right";
  }
  
  	/*
  int pay, a, answer;
  string op;
  
  cin >> pay >> a;
  answer = pay % 500 - 1*a;
  
  if(answer <= 0){
  	cout << "Yes";
  }
  else{
    cout << "No";
  }
  */
}