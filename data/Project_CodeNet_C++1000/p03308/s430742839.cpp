#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,maxA=0,minA=1e9+7;
  cin >> N;
  for(int i=0;i<N;i++){
    int A;
    cin >> A;
    maxA=max(maxA,A);
    minA=min(minA,A);
  }
  cout << maxA-minA << endl;
}