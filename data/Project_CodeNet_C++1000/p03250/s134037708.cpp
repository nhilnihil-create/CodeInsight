#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
  int a,b,c,m;
  cin >> a >> b >> c;
  m=max(a,max(b,c));
  cout << a+b+c+m*9 << endl;
}