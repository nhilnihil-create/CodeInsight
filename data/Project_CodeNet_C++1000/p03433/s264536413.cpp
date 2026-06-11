#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,n;
  cin >> n;
  cin >> a;
  b=n%500;
  if(a>b || a==b){
    cout << "Yes";
  }else{
    cout  << "No";
  }
}
    
