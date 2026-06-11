#include <bits/stdc++.h>
using namespace std;
const int maxval = 1e9 + 1;
int main(){
  int n; cin >> n;
  int arr[n + 1];
  memset(arr,0,sizeof(arr));
  //int minval = -1;
  for(int i = 0; i < n; ++i){
    cin >> arr[i];
  }
  int l[n + 2];
  int r[n + 2];
  l[0] = 0;
  r[n + 1] = 0;
  l[1] = arr[0];
  r[n] = arr[n - 1];
  for(int i = 2; i < n + 1; ++i){
    l[i] = __gcd(l[i-1],arr[i - 1]);
    //cout << l[i] << '\n';
    r[n - i + 1] = __gcd(r[n - i + 2],arr[n - i]);
    //cout << r[n - 1 -i] << '\n';
    //cout << l[i] << ' ' << r[n - i + 1] << '\n';
  }
 // cout << l[n] << '\n';
  int x_2 = maxval;
  int leasthcf = maxval;
  for(int i = 1; i < n + 1; ++i){
    int x = __gcd(l[i],r[i + 1]);
    int y = __gcd(l[i - 1],r[i + 1]);
    //cout << x << ' ' << y << '\n';
    if(x <= leasthcf){
      x_2 = ( x == leasthcf ? max(x_2,y) : y );
     // cout << x_2 << '\n';
      leasthcf = x;
    }
  }
  cout << (x_2 > l[n] ? x_2 : l[n]) << '\n';
}
