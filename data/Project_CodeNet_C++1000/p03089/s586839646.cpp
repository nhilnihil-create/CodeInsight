#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
using namespace std;
using ll = long long;
int main(){
  int n;
  cin >> n;
  vector<int> b(n);
  bool ok = true;
  int maxi = 1;
  for(int i = 0; i < n; i++) {
    cin >> b[i];
    if(b[i] > i + 1){
      ok = false;
    }
    maxi = max(maxi, b[i]);
  }
  if(!ok){
    cout << -1 << '\n';
    return 0;
  }
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    for(int j = n - 1 - i; j >= 0; j--){
      if(b[j] == j + 1) {
        a[i] = j + 1;
        b.erase(b.begin() + j);
        break;
      }
    }
  }
  reverse(a.begin(), a.end());
  for(int i = 0; i < n; i++){
    cout << a[i] << '\n';
  }
  return 0;
}