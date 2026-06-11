#include "bits/stdc++.h"
using namespace std;
 
#define REP(i, n) for(ll i = 0;i < n;i++)
#define REP1(i, n) for(ll i = 1;i < n;i++)
#define REPR(i, n) for(ll i = n-1;i >= 0;i--)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
 
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
 
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
 
#define pb(a) push_back(a)
 
int now,n,k;
 
 
int main(){
  int ans=0;
  
  vector<int> ain(6);
  vector<int> a(4);
  REP(i,6){
    cin>>n;
    a[n-1]+=1;
  }
  
  n=0;
  REP(i,4){
    if (a[i]>=3){n=1;}
    if (a[i]==0){n=1;}
  }
 
  if (n==0){
    cout <<"YES"<<endl;
  }else{
    cout <<"NO"<<endl;
  }
  return 0;
}