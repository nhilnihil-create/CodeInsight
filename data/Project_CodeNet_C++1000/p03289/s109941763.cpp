#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define REP(i, n) for (LL i = 0; i < (LL)(n); i++)
#define REP2(i, n) for (LL i = 1; i <= (LL)(n); i++)
#define FOR(i, m, n) for (LL i = m; i < n; i++)
#define SORT(x) sort(x.begin(), x.end())
#define RSORT(x) sort(x.begin(), x.end(),greater<int>())
#define REVE(x) reverse(x.begin(), x.end())
#define ALL(x) (x).begin(), (x).end()
#define SUM(x) accumulate(x.begin(), x.end(),0)
#define VLL(v,n) vector<LL> v(n); REP(i,n)cin>>v[i];
#define VSTR(v,n) vector<string> v(n); REP(i,n)REP(i,n)cin>>v[i];
LL INF = 1e9 + 1;
LL MOD = 1e9+7;
  LL a,b,c,d,e,n,m,l,r,x,y,z,ans=100000000,ans2=0,cnt=0;
string s,S,t;
bool flag=false;
int main() {
long double x;
ios_base::sync_with_stdio(false);
cin>>S;n=S.size();
for(int i=2;i<n-1;i++){
  if(S[i]=='C'){
    cnt++;
    a=i;
  }
}
if(cnt!=1){
  cout <<"WA"<<endl;
   return 0;
}
REP(i,n){
  if(i!=0&&a!=i){
    if(isupper(S[i])){
    cout <<"WA"<<endl;
    return 0;
  }
 }
}
if(S[0]!='A'){
 cout << "WA";
   return 0;
}
cout <<"AC";
   return 0;
}