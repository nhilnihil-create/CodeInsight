#include <bits/stdc++.h>
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
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
lli gcd(lli num1, lli num2){
    return num2 != 0 ? gcd(num2, num1 % num2) : num1;
}
lli lcm(lli num1, lli num2){
    return num1 / gcd(num1, num2) * num2;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  lli A,B,C,D,E,H,W,M,K,L,R,N,num=0,sum=0,flag=0;string S,T;
  cin >> N >> M >> S >> T;
  map<int,char> mp;
  mp[0]=S[0];
  K=lcm(N,M);
  rep(i,1,N)mp[K/N*i]=S[i];
  rep(i,1,M)mp[K/M*i]=T[i];
  string X="";
  rep(i,0,N)X.pb(mp[K/N*i]);
  if(S!=X)flag=true;
  X="";
  rep(i,0,M)X.pb(mp[K/M*i]);
  if(T!=X)flag=true;
  if(flag)Out(-1);
  else Out(K);
}
  