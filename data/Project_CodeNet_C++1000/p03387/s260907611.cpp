#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int x=max(a,max(b,c));
  cout << 2+(3*x-a-b-c)/2-((3*x-a-b-c+1)%2)*2 << endl;
}