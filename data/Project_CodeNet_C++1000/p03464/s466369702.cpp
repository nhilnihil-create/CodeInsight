#include <bits/stdc++.h>
using namespace std;

int main(){
  int k;
  cin >> k;
  vector<long long> A(k);
  for (int i = 0; i < k; ++i){
    cin >> A[i];
  }
  long long minv = 2, maxv = 2;
  for (int i = k - 1; i >= 0; --i){
    long long tmp1;
    if (minv % A[i] == 0){
    	tmp1 = minv;
    }else{
    	tmp1 = A[i]*(minv / A[i] + 1);
    }
    if (tmp1 > maxv){
      cout << -1 << endl;
      return 0;
    }
    long long tmp2 = (maxv/A[i])*A[i];
    if (tmp2 < minv){
    	cout << -1 << endl;
      	return 0;
    }
    minv = tmp1;
    maxv = tmp2 + A[i] - 1;
  }
  cout << minv << " " << maxv << endl;
}
