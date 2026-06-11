#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> a(n), b(n);
  for(int i=0;i<n;i++) cin >> a[i] >> b[i];
  int m = 1000000000;
  for(int i=0;i<n;i++) if(a[i] > b[i] && m > b[i]) m = b[i];
  long long int sum = 0;
  for(int i=0;i<n;i++) sum = sum + a[i];
  if(m == 1000000000) cout << 0 << endl;
  else cout << sum - m << endl;
  return 0;
}
