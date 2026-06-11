#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#include<cmath>
#include<bitset>
#define ll long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n)  FFOR(i,0,n)
#define SORT(V) sort((V).begin(),(V).end())
#define INF ((1LL<<62)-(1LL<<31))
#define MOD 1000000007
using namespace std;

int main(){
  int N,ans=0;
  cin>>N;
  
  if(N%10==2) ans++;
  if((N%100)-(N%10)==20) ans++;
  if((N%1000)-(N%100)==200) ans++;
  if((N%10000)-(N%1000)==2000) ans++;
  
  cout<<ans<<endl;
}
