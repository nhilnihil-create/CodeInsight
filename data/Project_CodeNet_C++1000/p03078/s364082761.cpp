#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()

#define P pair<int, ll>

int main(){
  int X,Y,Z,K;cin>>X>>Y>>Z>>K;
  vll A(X),B(Y),C(Z);
  rep(i,X)cin>>A[i];
  rep(i,Y)cin>>B[i];
  rep(i,Z)cin>>C[i];
  vll bc(1001000,0);
  rep(i,Y)rep(j,Z){
    bc[i*1000+j] = B[i] + C[j];
  }
  sort(all(bc),greater<ll>());
  sort(all(A),greater<ll>());
  auto compare = [&](auto const& a,auto const& b){ return a.second < b.second;};
  priority_queue <P, vector<P>, decltype(compare)> pos_sum{compare};
  rep(i,X){
    int pos = 0;
    ll sum = A[i] + bc[0];
    pos_sum.push(make_pair(pos,sum));
  }
  rep(i,K){
    P p = pos_sum.top();pos_sum.pop();
    if(p.first >= Y * Z) continue;
    cout << p.second << endl;
    p.first += 1;
    p.second -= bc[p.first - 1] - bc[p.first];
    pos_sum.emplace(p.first, p.second);
  }
}