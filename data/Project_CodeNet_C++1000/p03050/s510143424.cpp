#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;

int main() {
  int64_t N,answer=0;
  cin>>N;
  for(int64_t i=1;i*i<N;i++){
    if(N%i==0&&i<(N/i)-1) answer+=(N/i)-1;
  }
  cout<<answer;
}
