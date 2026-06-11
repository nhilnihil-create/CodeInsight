# include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  int A[200];
  cin >> N;
  for (int i=0; i<N; i++){
    cin >> A[i];
  }
  int min=A[0], max=A[0];
  for (int i=0; i<N; i++){
    if (A[i]<min){
      min=A[i];
    }
    else if (A[i]>max){
      max=A[i];
    }
  }
  cout << max-min << endl;
}
