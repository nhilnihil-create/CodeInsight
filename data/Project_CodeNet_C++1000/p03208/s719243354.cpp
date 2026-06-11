#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin >> n >> k;
  int h[n];
  for(int i=0;i<n;i++)cin >> h[i];
  sort(h,h+n);
  int m=2000000000;
  for(int i=0;i<n-k+1;i++){
    if(m>abs(h[i]-h[i+k-1]))m=abs(h[i]-h[i+k-1]);
  }
  cout << m;
}
