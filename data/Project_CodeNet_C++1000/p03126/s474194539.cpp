#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  int K,tmp,A[M],res=0;
  for(int h=0;h<M;h++){
    A[h] = 0;
  }
  
  for(int i=0;i<N;i++){
    cin >> K;
    for(int j=0;j<K;j++){
      cin >> tmp;
      A[tmp-1]++;
    }
  }
  for(int h=0;h<M;h++){
    if(A[h]==N){
      res++;
    }
  }
  cout << res << endl;
  return 0;
}