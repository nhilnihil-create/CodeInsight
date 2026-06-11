#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()


int main(){
  ll N,M,Q;cin>>N>>M>>Q;
  int v[N+1][N+1];
  rep(i,N+1)rep(j,N+1)v[i][j]=0;
  rep(i,M){
    ll l,r;cin>>l>>r;
    v[l][r]++;
  }
  for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)v[i][j]+=v[i][j-1];
	for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)v[i][j]+=v[i-1][j];
  rep(i,Q){
    ll p,q;cin>>p>>q;
    cout << v[q][q]+v[p-1][p-1]-v[q][p-1]-v[p-1][q] << endl;
  }
}