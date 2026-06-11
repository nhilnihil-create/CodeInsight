#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b;
  cin >> n >> a >> b;
  int X = 0;
  if (n < a + b){
    X = a + b - n;
  }else{
    X = 0;
  }
  cout << min(a,b) << " " << X << endl;
}