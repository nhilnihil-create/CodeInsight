#include<iostream>
#include<vector>
using namespace std;
int main() {
  int K;
  cin >> K;
  vector<long long> A(K);
  int i;
  for(i=0;i<K;i++)cin >> A[K-i-1];
  long long l = 2,u = 2;
  bool f = true;
  for(i=0;i<K;i++) {
    l = ((l-1)/A[i]+1)*A[i];
    u = (u/A[i]+1)*A[i]-1;
    if(l > u)f = false;
  }
  if(f)cout << l << " " << u << endl;
  else cout << -1 << endl;
}
