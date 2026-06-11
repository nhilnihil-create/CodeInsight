#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  long long sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
  }
  int ma = *max_element(a.begin(), a.end());
  sum -= ma;
  if(ma < sum) cout << "Yes" << endl;
  else cout << "No" << endl;
}