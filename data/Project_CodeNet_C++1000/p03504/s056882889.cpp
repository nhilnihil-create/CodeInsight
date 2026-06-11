#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
   int n,C;cin>>n>>C;
   vector<int> v(2*(1e+5)+3,0); 
   vector<vector<int>> x(C,vector<int>(2*(1e+5)+3,0));
   rep(i,n){
       int s,t,c;cin>>s>>t>>c;s*=2;t*=2;c--;
       if(x[c][s]==0) v[s]++;
       for(int j=s+1;j<=t-1;j++) v[j]++;
       if(x[c][t]==0) v[t]++;
       x[c][s]++;
       x[c][t]++;
   }
   int res=0;
   rep(i,2*(1e+5)+3) chmax(res,v[i]);
   cout<<res<<endl;
}