#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,X,sum=0,count=0;
  cin >> N >> X;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  sort(A.begin(),A.end());
  int i=0;
  while(X>sum){
    if(i==N){
      break;
    }
    sum+=A.at(i);
    count++;
    i++;
  }
  if(sum<X){
    count--;
  }
  if(sum>X){
    count--;;
  }
  cout << max(0,count) << endl;
}
