#include <bits/stdc++.h>
using namespace std;
signed gcd(long long x, long long y) {
    if (y == 0)return x;
    return gcd(y, x % y);
}
int main(){
  int N;cin>>N;
  vector<int>A(N);
  vector<int>B(N);
  vector<int>C(N);
  for(int i=0;i<N;i++){cin>>A[i];if(i==0)B[i]=A[i];else B[i]=gcd(B[i-1],A[i]);}
  C[N-1]=A[N-1];
  for(int i=N-2;i>=0;i--)C[i]=gcd(C[i+1],A[i]);
  int ans=0;
  for(int i=0;i<N;i++){
    if(i==0)ans=max(ans,C[1]);
    else if(i==N-1)ans=max(ans,B[N-2]);
    else ans=max(ans,gcd(B[i-1],C[i+1]));
  }
  cout<<ans<<endl;
}