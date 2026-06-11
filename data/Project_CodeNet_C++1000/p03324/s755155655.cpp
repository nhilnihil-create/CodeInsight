#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,x;
  cin >> a >> x;
  if(a==0 && x==100){cout << 101 << endl;}
  else if(a==0 && x!=100){cout << x << endl;}
  else if(a==1 && x==100){cout << 101*100 << endl;}
  else if(a==1 && x!=100){cout << x*100 << endl;}
  else if(a==2 && x!=100){cout << 10000*x << endl;}
  else if(a==2 && x==100){cout << 10000*101 << endl;}
}

