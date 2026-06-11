#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int main(){
 int n;
  cin >>n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  
  int x,y;
  x=*(upper_bound(a.begin(),a.end(),(a[n-1]/2))-1);
  y=*upper_bound(a.begin(),a.end(),(a[n-1]/2));
  if(a[n-1]-2*x<= 2*y-a[n-1]) cout << a[n-1] << " " << x << endl;
  else cout << a[n-1] << " " << y << endl;
}