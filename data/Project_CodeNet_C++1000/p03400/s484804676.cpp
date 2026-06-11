#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,d,x;
  cin >> n >> d >> x;
  vector<int>a (n);
  for(int i=0;i<n;i++){
      cin >> a[i];
      
    }
  d--;
  int ans =n;
  for(int i=0;i<n;i++){
      ans += d/a[i];
  }
  cout << ans + x << endl;
}
