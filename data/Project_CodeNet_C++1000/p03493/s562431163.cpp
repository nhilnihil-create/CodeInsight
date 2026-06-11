#include <bits/stdc++.h>
using namespace std;
int main(){
  int s;
  cin>>s;
  int a1=s%2;
  s-=a1;
  int a2=s/10%2;
  s-=10*a2;
  int a3=s/100%2;
  cout<<a1+a2+a3<<endl;
}
