#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,x,y;
  cin >> a>>b>>c>>x>>y;
  int minimum=1000000000;
  for(int i=0;i<=max(x,y);i++){
    int sum=0;
    sum += 2*i*c;
    sum+=max(0,(x-i)*a)+max(0,(y-i)*b);
    minimum =min(minimum,sum);
  }
cout<<minimum<<endl;
}
