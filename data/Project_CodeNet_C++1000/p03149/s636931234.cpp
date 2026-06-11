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
  int A[4],L[10];
  cin>>A[0]>>A[1]>>A[2]>>A[3];
  REP(i,10) L[i]=0;
  for(int i=0; i<4; ++i){
    if(A[i]==1) L[1]++;
    if(A[i]==4) L[4]++;
    if(A[i]==7) L[7]++;
    if(A[i]==9) L[9]++;
  }
  if(L[1]==1 && L[4]==1 && L[7]==1 && L[9]==1) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}