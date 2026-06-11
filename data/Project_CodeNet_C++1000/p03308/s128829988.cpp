#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){


  int n;
  cin >> n;

  int a[n];
 
  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  sort(a, a+n);


  cout << a[n-1] - a[0] << endl;


  for(int i=0;i<n;i++){
//    cout << a[i] << endl;
  }
}