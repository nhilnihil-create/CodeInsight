#include <bits/stdc++.h>
using namespace std;

int main(){
  long long X,Y,A=pow(10,18);
  cin >> X >> Y;
  if(X%Y==0){
    cout << -1 << endl;
  }
  else{
    cout << X << endl;
  }
}