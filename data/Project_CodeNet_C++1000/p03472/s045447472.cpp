#include <bits/stdc++.h>
using namespace std;

int main(){
  long n, h;  cin >> n >> h;  
  vector<long> a(n), b(n);
  for(int i=0; i<n; i++)  cin >> a[i] >> b[i];
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  long damage = 0, i = 0;
  while(i<n && damage<h && b[i]>=a[0])
    damage += b[i++];
  
  while(damage < h){
    damage += a[0];
    i++;
  }

  cout << i << endl;
  return 0;
}
