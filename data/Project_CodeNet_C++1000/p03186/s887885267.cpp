#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  cout << b+c-max((c-a-b)-1,0) << endl;
}