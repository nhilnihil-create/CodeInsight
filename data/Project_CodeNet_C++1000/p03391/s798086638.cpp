#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#include<cmath>
#include<bitset>
#include<queue>
#define ll long long
#define itn int
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n)  FFOR(i,1,n)
#define SORT(V) sort((V).begin(),(V).end())
#define REVERSE(V) reverse((V).begin(),(V).end())
#define INF ((1LL<<62)-(1LL<<31))
#define MOD 1000000007
using namespace std;

ll N,M,K,ans=0,mn=INF;
string S,T;
vector<int> P,Q;
vector<pair<int,int>> PP;
bool CAN=false;


int main(){
  cin>>N;
  ll A[N],B[N];
  REP(i,N){
    cin>>A[i]>>B[i];
    ans+=B[i];
    if(A[i]>B[i]) mn=min(mn,B[i]);
  }
  if(mn!=INF) cout<<ans-mn<<endl;
  else cout<<0<<endl;
}