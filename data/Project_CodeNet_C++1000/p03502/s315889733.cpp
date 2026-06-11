#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int x=0;
  int y=N;
  string z="No";

  while(y>10){
    x+=y%10;
    y/=10;
  }
  x+=y;
  if (N%x==0)
  z = "Yes";

  cout <<z<<endl;

}
