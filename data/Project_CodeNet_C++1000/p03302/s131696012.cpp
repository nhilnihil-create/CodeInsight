#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;cin>>a>>b;
  int p=(a+b==15),q=(a*b==15);
  cout <<(p?"+\n":(q?"*\n":"x\n"));
}