#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
  int a,b;
  cin >> a >> b;
  int x;
  x = b - a - 1;
  cout << x * (x+1) / 2 - a << endl;
}