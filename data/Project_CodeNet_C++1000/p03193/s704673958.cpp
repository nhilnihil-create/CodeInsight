#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,h,w;
  cin >> n >> h >> w;
  int a[n],b[n],c=0;
  for(int i=0;i<n;i++){
    cin >> a[i] >> b[i];
    if(a[i]>=h&&b[i]>=w)c++;
  }
  cout << c;
}