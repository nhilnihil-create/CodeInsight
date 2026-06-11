#include<bits/stdc++.h>
using namespace std;

int main(){
 int N,X;
  cin >> N >> X;
  int sum = 0;
  vector<int> a(N);
  for(int i=0; i<N; i++){
    cin >> a[i];
	sum += a[i];    
  }
  sort(a.begin(),a.end());
  cout << N + (X-sum)/a[0] << "\n";
  return 0;
}