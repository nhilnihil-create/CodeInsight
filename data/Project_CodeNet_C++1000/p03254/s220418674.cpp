#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  long N,X,all=0;
  cin >> N >> X;
  vector<long> A(N);
  for(long i=0;i<N;i++){
    cin >> A.at(i);
    all += A.at(i);
  }
  sort(A.begin(),A.end());
  if(X > all){
    cout << N-1 << endl;
  }else if(X<all){
    int sum = 0;
 	while(X>-1){
      X = X - A.at(sum);
      sum++;
    }
  	cout << sum-1 << endl;
  }else{
    cout << N << endl;
  }
  return 0;
}