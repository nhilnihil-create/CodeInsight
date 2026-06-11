#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define lli long long int
#define uli unsigned long long int
#define INF 999999999999999999
#define rep(i,m,n) for(lli i = m;i < n;i++)
#define rrep(i,m,n) for(lli i=m-1;i>=n;i--)
#define pb(n) push_back(n)
#define UE(N) N.erase(unique(N.begin(),N.end()),N.end());
#define Sort(n) sort(n.begin(), n.end())
#define Rev(n) reverse(n.begin(),n.end())
#define Out(S) cout << S << endl
#define NeOut(S) cout << S
#define HpOut(S) cout << setprecision(25) << S << endl
#define Vec(K,L,N,S) vector<L> K(N,S)
#define DV(K,L,N,M,S) vector<vector<L>> K(N,vector<L>(M,S))
#define TV(K,L,N,M,R,S) vector<vector<vector<L>>> K(N,vector<vector<L>>(M,vector<L>(R,S)))
#define pint pair<lli,lli>
#define paf(L,R) pair<L,R>
#define mod 1000000007
#define MAX 10000000
#define ALL(a)  a.begin(),a.end()
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  lli A,B,C,D,E,F,N,M,K,L,X,Y,Z,H,W,sum=0,num=0,flag=0;string S,T;
  cin >> N;
  DV(Pif,int,3,N,0);
  rep(i,0,N)cin >> Pif[0][i] >> Pif[1][i] >> Pif[2][i];
  rep(i,0,101)rep(j,0,101){
    map<int,int>mp;
    rep(k,0,N)if(Pif[2][k]!=0)mp[abs(i-Pif[0][k])+abs(j-Pif[1][k])+Pif[2][k]]++;
    if(mp.size()==1){
      flag=1;
      for(auto v:mp)num=v.first;
      rep(k,0,N)if(Pif[2][k]!=max(0LL,num-abs(i-Pif[0][k])-abs(j-Pif[1][k])))flag=0;
      if(flag){
        cout << i << " " << j << " " << num << endl;
        return 0;
      }
    }
  }
}
