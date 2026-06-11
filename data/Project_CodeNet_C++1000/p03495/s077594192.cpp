#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K,sum,owt;
  cin >>N>>K;
  int A[N];
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  map<int,int> S;
  int a=0;
  for(int i=0;i<N;i++){
    S[A[i]]++;
  }
  int T[S.size()];
  for(int i=0;i<S.size();i++){
    if(S[i]!=0) sum++;
    T[i] = S[i];
  }
  sort(T,T+S.size());
  if(sum<=K){
    a=0;
  }
  else{
    int E=sum-K;
    for(int i=0;owt<E;i++){
      if(T[i]!=0){
        a +=T[i];
        owt ++;
      }
    }
  }
  cout << a << endl;
}
      