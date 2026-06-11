#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  int A_tmp, A[N]={0};
  for (int i=0;i<N;i++){
    cin >> A_tmp;
    A[A_tmp-1]++;
  }
  sort(A, A+N, greater<int>());
  
  int64_t retval = 0;
  for (int i=K;i<N;i++){
    retval += A[i];
  }

  cout << retval << endl;
}