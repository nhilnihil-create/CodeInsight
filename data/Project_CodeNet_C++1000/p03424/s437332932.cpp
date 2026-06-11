#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
int  N;
    cin >> N ;
string A;
bool a=false;
  for (int i = 0; i < N; ++i){
  cin >> A ;
    if(A=="Y") a=true;
  }
 if (a==true)  cout << "Four"<< endl;  
  else cout << "Three" << endl;
}
