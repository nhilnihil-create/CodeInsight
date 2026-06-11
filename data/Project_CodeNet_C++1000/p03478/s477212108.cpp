#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int sum=0;
  for(int i=1;i<=n;i++){
      int n1,n2,n3,n4,n5,nn;
      n1=i%10;
      n2=i%100/10;
      n3=i%1000/100;
      n4=i%10000/1000;
      n5=i/10000;
      nn=n1+n2+n3+n4+n5;
  	if(nn>=a&&nn<=b){sum+=i;}
  }
  cout << sum <<endl;
}
