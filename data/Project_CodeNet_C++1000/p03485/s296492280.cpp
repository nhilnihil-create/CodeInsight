#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin >> a >> b;
  if(a % 2 == 0 && b % 2 == 0){
    int x = (a + b) / 2;
    cin >> x;
    cout << x << endl;
  }
  else if(a % 2 == 1 && b % 2 == 1){
    int x = (a + b) / 2;
    cin >> x;
    cout << x << endl;
  }
  else{
    int x = 0.5 +(a + b) * 0.5;
    cin >> x;
    cout << x << endl;
  }
 
}
