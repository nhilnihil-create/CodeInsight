#include <bits/stdc++.h>
using namespace std;
#define REP(i,N) for(i=0;i<N;i++)
#define INF 1e18
typedef long long ll;

int main(void){
  int N; cin >> N;
  //累積和
  ll A[N+1];
  A[0] = 0;
  int i;REP(i,N){
    ll x;cin >> x;
    A[i+1] = A[i]+x;
  }
  int left = 1,center,right=3;
  ll minimum = INF;
  for(center=2; center<N-1; center++){
    int l,r;
    ll m = INF;
    for(l = left; l<center; l++){
      if(m < abs(A[l] - (A[center] - A[l]))) break;
      else{
        m = abs(A[l] - (A[center] - A[l]) );
      }
    }
    left = l-1;

    m = INF;
    for(r = right; r < N; r++){
      if(m < abs( (A[r] - A[center]) - (A[N] - A[r]) ) ) break;
      else{
        m = abs( (A[r] - A[center]) - (A[N] - A[r]) );
      }
    }
    right = r-1;
    ll Max = max(max(A[left], A[center]-A[left]),max(A[right]-A[center],A[N]-A[right]));
    ll Min = min(min(A[left], A[center]-A[left]),min(A[right]-A[center],A[N]-A[right]));
    if(abs(Max-Min) < minimum){
      minimum = abs(Max-Min);
    }
  }
  cout << minimum << endl;
  return 0;
}
