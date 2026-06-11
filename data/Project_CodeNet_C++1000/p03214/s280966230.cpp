#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n, sum = 0, ans = 1LL << 60, tot = 0;
  cin >> n;
  vector<long long> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
  }
  for(int i = 0; i < n; i++){
    if(abs((a[i] * n) - sum) < ans ){
      tot = (i);
      ans = abs((a[i] * n) - sum);
    }
  }
  cout << tot << endl;
}
