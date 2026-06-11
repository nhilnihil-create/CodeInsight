#include <bits/stdc++.h>
using namespace std;
 
int main() {
int a,b,c,k;
  cin>>a>>b>>c>>k;
  int d =max({a,b,c});
  int sum=d;
  for (int i = 0; i < k; i++) {
 sum *=2;
}
 int e= a+b+c-d;
   sum +=e;
cout<<sum<<endl;
}