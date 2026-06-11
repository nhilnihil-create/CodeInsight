#include<vector>
#include<iostream>
#include<cmath>

using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> A(n+2,0);
  for(int i=0; i<n; i++){
    cin >> A[i+1];
  }
  int ans = 0;
  for(int i=1;i<n+2;i++){
    ans += abs(A[i]-A[i-1]);
  }
  for(int i=1; i < n+1; i++){
    cout << ans - abs(A[i]-A[i-1]) - abs(A[i]-A[i+1]) + abs(A[i-1]-A[i+1]) << endl;
  }
}
