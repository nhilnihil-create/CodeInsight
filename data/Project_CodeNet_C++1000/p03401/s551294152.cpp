#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n+2];
  for(int i=1;i<n+1;i++){
    cin >> a[i];
  }
  a[0]=0;
  a[n+1]=0;
  int y=0;
  for(int i=1;i<2+n;i++){
    y=y+abs(a[i]-a[i-1]);
  }
  int u;
  for(int i=1;i<n+1;i++){
    u=y+abs(a[i+1]-a[i-1])-abs(a[i]-a[i-1])-abs(a[i]-a[i+1]);
    cout << u << endl;
  }
}
