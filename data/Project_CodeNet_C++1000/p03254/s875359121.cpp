#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,x;
  cin >> n >> x;
  int a[n];
  for(int i=0;i<n;i++)cin >> a[i];
  sort(a,a+n);
  int b=0;
  for(int i=0;i<n;i++){
    x-=a[i];
    if(x>=0)b++;
    else break;
  }
  if(b==n&&x>0)b--;
  cout << b;
}
