#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for(int i = 0; i < N; ++i) cin >> A[i];
  for(int i = 0; i < N; ++i) cin >> B[i];
  int ans = 0, mask = 0;
  for(int i = 0; i < 29; ++i){
    mask |= (1<<i);
    vector<int> a(N), b(N);
    for(int j = 0; j < N; ++j) a[j] = A[j]&mask;
    for(int j = 0; j < N; ++j) b[j] = B[j]&mask;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long c = 0;
    for(auto e : a){
      int l = (1<<i)-e, r = (1<<(i+1))-e;
      // count {bi | l <= bi < r}
      c += lower_bound(b.begin(), b.end(), r)
        - lower_bound(b.begin(), b.end(), l);
      l += (1<<(i+1));
      r += (1<<(i+1));
      c += lower_bound(b.begin(), b.end(), r)
        - lower_bound(b.begin(), b.end(), l);
    }
    
    if(c%2) ans |= (1<<i);
  }
  cout << ans << endl;
}
