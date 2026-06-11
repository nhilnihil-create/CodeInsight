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
  double avg = (double)sum / n;
  double mindf = 100.0;
  for(int i = 0; i < n; i++){
    double dif = abs(a[i] - avg);
    mindf = min(mindf, dif);
  }
  for(int i = 0; i < n; i++){
    if(abs(a[i]-avg)==mindf){
      cout << i << endl;
      return 0;
    }
  }
}
