#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

int main() {
  int N,Q; cin>>N>>Q;
  string S; cin>>S;
  vector<int> A(N,0);
  for(int i=1;i<N;i++){
    if(S.at(i)=='C'&&S.at(i-1)=='A') A.at(i)++;
    A.at(i)+=A.at(i-1);
  }
  rep(i,Q){
    int l,r,k; cin>>l>>r;
    r--;
    if(l==1) k=0;
    else{
      l--;
      k=max(A.at(l),A.at(l-1));
    }
    cout<<A.at(r)-k <<endl;
  }
}
