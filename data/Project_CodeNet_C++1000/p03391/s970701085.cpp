#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  vector<int> over(0);
  int64_t sum = 0;
  
  for(int i=0; i<N; i++){
    cin >> A[i];
    cin >> B[i];
    sum += A[i];
    if(A[i] > B[i]){
      over.push_back(B[i]);
    }
  }
  
  sort(over.begin(),over.end());
  if(over.size() == 0){
    cout << 0 << endl;
  }
  else{
    cout << sum - over[0] << endl;
  }
}