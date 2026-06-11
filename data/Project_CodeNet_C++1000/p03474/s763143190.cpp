
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, n) for (int i = 1; i <= (int)(n); i++)
#define FOR(i, m, n) for (int i = m; i<n; i++)
#define SORT(x) sort(x.begin(), x.end())
#define REVE(x) reverse(x.begin(), x.end())
#define ALL(x) (x).begin(), (x).end()
#define SUM(x) accumulate(x.begin(), x.end(),0);
#define vint(v,n) vector<int> v(n); REP(i,n) scanf("%lld", &v[i]);
#define vstr(v,n) vector<string> v(n); REP(i,n) scanf("%lld", &v[i]);
int k=0,n=0, m=0, l=0,r=0,a=0, b=0, c=0, d=0,e=0,ans=0,ans2=0,x=0,y=0;
string s,t,S;
signed main() {
  ios_base::sync_with_stdio(false);
    cin >> a>>b>>s;
  if(s[a]!='-'||(a+b+1)!=s.size()){
      cout << "No"<<endl;
    return 0;
  }
  REP(i,a+b+1){
      if(a!=i){
      if(s[i]<='9'&&s[i]>='0'){
      }else{
          cout << "No"<<endl;
        return 0;
      }
       }
  }
  cout << "Yes";
}
              
