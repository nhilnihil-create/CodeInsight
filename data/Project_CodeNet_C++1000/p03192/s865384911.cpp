#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
using namespace std;
int main(){
  int n, count=0;
  cin >> n;
  if(n/1000==2)count++;
  n-=n/1000*1000;
  if(n/100==2)count++;
  n-=n/100*100;
  if(n/10==2)count++;
  n-=n/10*10;
  if(n==2)count++;
  cout << count << endl;
}