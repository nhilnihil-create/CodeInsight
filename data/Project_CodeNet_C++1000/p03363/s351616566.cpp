#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N; cin >> N;
  vector<long long> A(N);
  for(int i=0; i<N; i++) cin >> A[i];
  
  vector<long long> B(N+1,0);
  map<long long,long long> nums;
  for(int i=1; i<=N; i++) B[i] = B[i-1] + A[i-1];
  for(int i=0; i<=N; i++) nums[B[i]]++;
  
  long long ans =0;
  for(auto it : nums) {
    long long num = it.second;
    ans += num*(num-1)/2;
  }
  cout << ans << endl;
}