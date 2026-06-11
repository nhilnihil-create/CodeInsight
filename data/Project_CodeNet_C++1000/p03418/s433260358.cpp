#include <bits/stdc++.h>
using namespace std;
int main(){
unsigned long N, K, ans; cin >> N >> K;
ans=(K)?(N-K+1)*(N-K)/2:N*(N-1)/2;
for(unsigned long i, b=K+1; b<=N; b++){
 for(i=2; (i-1)*b+K<=N && i*b-1<=N; i++){ ans+=(b-K); }
 if((i-1)*b+K<=N && i*b-1>N){ ans+=(N-((i-1)*b+K)+1); }
}
cout << ans << "\n";
}