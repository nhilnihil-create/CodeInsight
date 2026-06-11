#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<long long> a(n);
  long long M = -1001001001, m = 1001001001;
  for(int i = 1; i <= n; i++){
    cin >> a.at(i-1);
    a.at(i-1) -= i;
  }
  sort(a.begin(), a.end());
  long long ans1 = 0, ans2 = 0;
  long long tmp1;
  if(n >= 2) tmp1 = a.at(n/2 - 1);
  else tmp1 = 0;
  long long tmp2 = a.at(n/2);
  for(int i = 0; i < n; i++){
    ans1 += abs(a.at(i) - tmp1);
    ans2 += abs(a.at(i) - tmp2);
  }
  cout << min(ans1, ans2) << endl;
}
