#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,a;
  cin >> n;
  cin >> a;
  int b;
  b = n % 500;
  if(b <= a){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}