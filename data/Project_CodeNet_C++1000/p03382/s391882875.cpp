#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int OO = 1e9;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int n;
  cin >> n;
  int a[n];
  for(int i = 0;i < n;i++)
    cin >> a[i];
  sort(a, a + n);
  int mn, mni;
  mn = 1e9;
  for(int i = 0;i < n - 1;i++){
    int x = a[n - 1] / 2;
    if(a[n - 1] & 1){
      if(a[i] <= a[n - 1] / 2 && a[n - 1] / 2 - a[i] < mn){
        mn = a[n - 1] / 2 - a[i];
        mni = i;
      }else if(a[i] > a[n - 1] / 2 && a[i] - a[n - 1] / 2 - 1 < mn){
        mn = a[i] - a[n - 1] / 2 - 1;
        mni = i;
      }
    }else{
      if(abs(a[i] - a[n - 1] / 2) < mn){
        mn = abs(a[i] - a[n - 1] / 2);
        mni = i;
      }
    }
  }
  cout << a[n - 1] << ' ' << a[mni];
  return 0;
}
