#include <bits/stdc++.h>

#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int n;
cin>>n;
vector<int>h(n);
rep(i,n)cin>>h[i];
const int INIT=300;
int min_val=INIT;
int ans=0;
int l;
do{
    l=0;
    rep(r,n+1){
       if(r==n || h[r]==0){
           reps(j,r,l){
               h[j]-=min_val;
           }
           if(min_val!=INIT)ans+=min_val;
           l=r+1;
           min_val=INIT;           
       }
       else{
           min_val=min(min_val,h[r]);
       }
   }
   
}while(accumulate(h.begin(),h.end(),0));
cout<<ans<<endl;
return 0;
}