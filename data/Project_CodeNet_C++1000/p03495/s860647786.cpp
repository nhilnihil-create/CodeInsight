#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n,k;
  int a[200010];
  cin >> n >> k;
  for(int i=0; i<n; ++i) {cin >> a[i];}
  int num[n+1] = {0};
  for(int i=0; i<n; ++i) {num[a[i]]++;}
  sort(num, num+n+1);
  int sum = 0;
  for(int i=0; i<=n-k; ++i){ sum += num[i]; }
  cout << sum << endl;
}