#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  int even=0;
  for(int i=0; i<N; i++){
    cin >> A[i];
    if(A[i]%2==0) even++;
  }
  
  int sim=pow(3,N);
  int all_odd=pow(2,even);
  
  cout << sim-all_odd <<endl;
}