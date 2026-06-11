#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  string s = (a==b && b==c) ? "Yes" : "No";
  cout << s;
}