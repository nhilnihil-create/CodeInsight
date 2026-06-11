#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
  cin >> n;
  int sum = 0;
  vector<int> a(n);
  for(int i = 0; i < n; i++){ cin >> a[i]; sum+= a[i];}
  cout << (sum - *max_element(a.begin(), a.end()) > *max_element(a.begin(), a.end()) ? "Yes" : "No") << endl;
}