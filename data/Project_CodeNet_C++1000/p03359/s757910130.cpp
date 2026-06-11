#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b; cin>>a>>b;
  if(b>=12) b=12;
  if(a>b) b=a-1;
  cout << min(a,b) << endl;
}