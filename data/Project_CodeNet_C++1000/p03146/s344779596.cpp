#include <bits/stdc++.h>
using namespace std;

int main() {
int s;
cin >> s;
int cnt=1;
  while(1)
  {
    
  if(s==1 || s==2 || s==4)
  {
    cnt+=3;
    break;
  } 
  if(s%2==0)
  {
    s/=2;
    cnt++;
  }
  else
  {
    s=3*s+1;
    cnt++;
  }
  }
cout << cnt << endl;

  return 0;
}