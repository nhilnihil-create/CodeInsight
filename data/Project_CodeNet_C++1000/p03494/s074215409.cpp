#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,mincount=1e9;
  cin >> N;
  for(int i=0;i<N;i++){
    int A,count=0;
    cin >> A;
    while(A%2==0){
      count++;
      A/=2;
    }
    mincount=min(mincount,count);
  }
  cout << mincount << endl;
}