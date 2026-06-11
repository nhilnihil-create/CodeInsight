#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;

int main() {
  int a;
  cin>>a;
  if(a<1200) cout<<"ABC"<<endl;
  else if(a>=1200 && a<2800) cout<<"ARC"<<endl;
  else cout<<"AGC"<<endl;
  return 0;
}
