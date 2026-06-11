#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long N,X,P,Q;
vector<long long> A,B;

long long sub1(long long i){
  long long q=N*X;
  for (long long j=1;j<=N;j++){
    long long t=(j-1)/i;
    if (t>0){
      q+=(2*t+3)*A[j];
    }else{
      q+=5*A[j]+X;
    }
  }
  return q;
}
long long sub2(long long i){
  if (i>=0)
    return sub1(i+1)-sub1(i);
  else return 0;
}

bool comp(long long x,long long y){
  return sub2(x)<sub2(y);
}

int main(){
  cin >> N >> X;
  A.assign(N+10,0);
  B.assign(N+10,0);
  for (long long i=1;i<=N;i++){
    B[i]=i;
    cin >> A[N+1-i];
  }
  cout << sub1(upper_bound(&B[1],&B[N],-1,comp)-&B[0]) << endl;
}
