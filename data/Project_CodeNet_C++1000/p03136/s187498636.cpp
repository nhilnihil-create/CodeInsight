#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a, a+n);
  int sum = 0;
  for(int i = 0; i < n-1; i++) sum += a[i];
  if(a[n-1] < sum) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}