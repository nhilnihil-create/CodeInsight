#include<bits/stdc++.h>
using namespace std;
#define long long long

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  for(int i=0; i<N; i++){
    cin >> B[i];
  }
  vector<int> C;
  long S=0, S1=0;
  int ans=0;
  for(int i=0; i<N; i++){
    if(A[i]>=B[i]){
      S1+=A[i]-B[i];
      C.push_back(A[i]-B[i]);
    }else{
      S+=B[i]-A[i];
      ans++;
    }
  }
  if(ans==0){
    cout << "0" << endl;
    return 0;
  }else if(S1<S){
    cout << "-1" << endl;
    return 0;
  }
  sort(C.begin(), C.end(), greater<int>());
  for(int i=0; i<C.size(); i++){
    S=S-C[i];
    ans++;
    if(S<=0) break;
  }
  cout << ans << endl;
  return 0;
}