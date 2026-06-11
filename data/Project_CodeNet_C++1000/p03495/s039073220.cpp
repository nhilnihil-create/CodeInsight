#include<bits/stdc++.h>
#include<math.h>
using namespace std;
 
int main(){
  int N, K, A[200010]={0};
  cin >> N >> K;
  int A_tmp;
  for (int i=0;i<N;i++){
    cin >> A_tmp;
    A[A_tmp-1]++;
  }
  sort(A, A+N, greater<int>());
  
  int64_t retval = 0;
  for (int i=K;i<N;i++){
    if (A[i]==0) break;
    retval += A[i];
  }
  cout << retval << endl;
}
 