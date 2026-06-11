#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int X, D, N, A, suma=0;
  cin >> N;
  cin >> D >> X;
  int arr[D];
  memset(arr, 0, sizeof(arr));
  arr[0] = N;
  while(N--){
    cin >> A;
    for(int i=1; A*i<D; ++i){
      arr[A*i]++;
    }
  }
  for(int i=0; i<D; ++i){
    suma+=arr[i];
  }
  cout << suma+X;
  return 0;
}