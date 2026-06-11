#include <bits/stdc++.h>
using namespace std;

int main() {
int A,B,K;
cin >>A>>B>>K;
int c=min(A,B);
int cnt =0;
for (int i = c; i >=1 ; i--)
{
  if(A%i==0 && B%i==0) cnt++;
  if(cnt==K)
  {
    cout << i <<endl;
    break;
  }
}

  return 0;
}