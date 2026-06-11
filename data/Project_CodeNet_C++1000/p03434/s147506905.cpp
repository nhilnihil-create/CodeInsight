#include <iostream>
#include <algorithm>
using namespace std;


int main(){
  int n;
  int A[110];
  int total1 = 0;
  int total2 = 0;
  cin >> n;
    for(int i = 0;i<n;i++){
    cin >> A[i];
  }
  sort(A,A+n,greater<int>());
  

  
  for(int i = 0;i<n;i++){
  if(i % 2 == 0){
    total1 += A[i];
  }else{
    total2 += A[i];
  }
  }
  cout << total1 - total2 << endl;
}
