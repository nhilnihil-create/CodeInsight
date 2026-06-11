#include <iostream>
using namespace std;

int n, a[10], ans;

int func(int a[], int i, int prod){
  if (i==n){
    ans += (prod%2==0);
  } else {
    func(a, i+1, prod*(a[i]-1)%2);
    func(a, i+1, prod*(a[i])%2);
    func(a, i+1, prod*(a[i]+1)%2);
  }
}

int main(void){
  cin >> n;
  for (int i=0; i<n; i++) cin >> a[i];
  func(a, 0, 1);
  cout << ans << endl;
  return 0;
}
