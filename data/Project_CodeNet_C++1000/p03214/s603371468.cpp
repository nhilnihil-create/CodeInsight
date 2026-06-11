#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  
   double mean=0;
  for(int i=0; i<n; i++){
    mean += a[i];
  }
  
  mean /= n;
  
  int t=n;
  double d=10000;
  for(int i=n-1; i>=0; i--){
    if(abs(a[i]-mean) <= d){
      d = abs(a[i]-mean);
      t = i;
    }
  }
  
  cout << t << endl;
	return 0;
}
