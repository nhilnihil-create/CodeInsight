#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
14111
とかは、4が4番目以降にでないとNG
N100少ない
[1] 1 1 2 2 1 2 3 2
[1] 1 2 2 1 2 3 2
1 [2] 2 1 2 3 2
1 [2] 1 2 3 2
[1] 1 2 3 2
1 2 [3] 2
1 [2] 2
1 [2]
1
n番目とnが合致してるうち、最大のものをとればいいのね
毎回100通り確認。100*100で余裕
*/
int main(){
  ll N; cin>>N;
  vector<ll> A(0,0), B(0,0);
  for(int i=0; i<N; i++){
    ll b; cin>>b;
    B.emplace_back(b);
  }
  for(ll i=0; i<N; i++){
    ll change=-1;
    ll Bsz=B.size();
    for(ll j=0; j<Bsz; j++)
      if(j+1==B[j]) change=max(change, j);
    if(change==-1){
      cout<<-1<<endl;
      return 0;
    }
    A.emplace_back(B[change]);
    B.erase(B.begin()+change);
  }
  for(int i=N-1; i>=0; i--)
    cout<<A[i]<<endl;
}