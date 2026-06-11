#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int a, b;
  cin >> a >> b;
  a--;
  int k;
  if(a%4==0)k=a;
  else if(a%4==1)k=1;
  else if(a%4==2)k=a+1;
  else k=0;
  int l;
  if(b%4==0)l=b;
  else if(b%4==1)l=1;
  else if(b%4==2)l=b+1;
  else l=0;
  cout << (k^l) << endl;
  return 0;
}