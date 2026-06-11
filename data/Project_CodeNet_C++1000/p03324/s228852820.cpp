#include <bits/stdc++.h>
using namespace std;

int main() {
  int d,n;
  cin>>d>>n;
  long long num=pow(100,d);
  if(n==100)cout<<num*n+num<<endl;
  else cout<<num*n<<endl;
  return 0;
}

