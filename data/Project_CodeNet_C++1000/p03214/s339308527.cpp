#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
  }
  int mindf = 1000;
  int ans = 0;
  for(int i = 0; i < n; i++){
    int d = abs(a[i]*n - sum);
    if(mindf > d){
      mindf = d;
      ans = i;
    }
  }
  cout << ans << endl;
}
