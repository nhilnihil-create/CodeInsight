#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long> a(n);
  for(int i=0; i<n; i++){
    cin >> a.at(i);
  }
  sort(a.begin(),a.end());
  int i=0;
  for(int j=0; j<n; j++){
    if(max(a[n-1]-a[i]*2,a[i]*2-a[n-1])>max(a[n-1]-a[j]*2,a[j]*2-a[n-1])){
      i=j;
    }
  }
  cout << a[n-1] << ' ' << a[i] << endl;
}