#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N, X;
  cin >> N >> X;
  vector<long long> x(N);
  for (long long i=0; i<N; i++) cin >> x[i];
  vector<long long> xsum(N);
  for (long long i=0; i<N; i++){
    if (i==0) xsum[i] = x[i];
    else xsum[i] = x[i] + xsum[i-1];
  }
  long long ans=(long long)0;
  for (long long i=1;i<=N;i++){
    long long tmp = X*N+i*X+xsum[N-1]*(long long)5;
    int flag = 0;
    for (long long j=N-1-i*2; j>-1; j-=i){
      tmp += xsum[j]*(long long)2;
      if (tmp<0) flag++;
    }
    if (ans == 0) ans = tmp;
    else if (flag==0) ans = min(ans, tmp);
  }
  cout << ans << endl;
}
