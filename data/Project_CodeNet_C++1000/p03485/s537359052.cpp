#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  
  if((a+b)%2 == 0){
    int x = (a+b)/2;
    cout << x << endl;
  }else{
    int x = (a+b)/2 +1;
    cout << x << endl;
  }
  
}
