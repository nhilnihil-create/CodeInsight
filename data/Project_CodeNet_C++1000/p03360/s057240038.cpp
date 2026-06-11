#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int k;
  cin >> k;
  if(a>=b&&a>=c)a=a*pow(2,k);
  if(b>=a&&b>=c)b=b*pow(2,k);
  if(c>=b&&c>=a)c=c*pow(2,k);
  cout << a+b+c;
}
