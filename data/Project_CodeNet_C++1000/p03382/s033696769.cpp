#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
// repeat for accumulational summention
#define Acu(i,n,m) for(int i=(n);i<=(m);i++)
#define ll long long
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int MAX=1e9;
int MOD=1e9+7;


int main(){
  int n;cin>>n;
  ll ansI=0,ansJ;
  ll a[n],b[n];
  REP(i,n){
    cin>>a[i];
    b[i]=a[i];
    ansI=max(a[i],ansI);
  }
  ll MEAN;
  (ansI%2==1)?MEAN=ansI/2+1:MEAN=ansI/2;
  REP(i,n){
    b[i]=abs(b[i]-MEAN);
  }
  ll temp=b[0];
  REP(i,n){
    temp=min(temp,b[i]);
    if(temp==b[i])ansJ=a[i];
  }
  cout<<ansI<<" "<<ansJ<<endl;
}
