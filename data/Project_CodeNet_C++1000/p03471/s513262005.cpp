#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,Y;
  cin>>n>>Y;
  Y=Y/1000;
  int x=-1,y=-1,z=-1;
  for (int i=0;i<=n;i++) {
    for (int j=0;j<=n-i;j++){
      if (i*10+j*5+n-i-j==Y) {
        x=i;
        y=j;
        z=n-i-j;
      }
    }
  }
  cout<<x<<' '<<y<<' '<<z<<endl;
}