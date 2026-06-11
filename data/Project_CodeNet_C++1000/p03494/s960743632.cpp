#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for(int k=0; k<N; k++)
    cin >> A[k];
  int x=0,y=0;
  
  for(;;){
    for(int j=0; j<N; j++){
      if(A[j]%10%2==0)
        x++;
      else
        break;
    }
    if(x == N){
      for(int l=0; l<N; l++)
        A[l]/=2;
      y++;
    }
    else
      break;
    x=0;
  }
      
  cout << y << endl;
}
