#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n,m;cin>>n>>m;
   priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > que;
   rep(i,n){
       ll a,b;cin>>a>>b;
       que.push({a,b});
   }
   ll now=m,res=0;
   while(now>0){
       auto p=que.top();que.pop();
       ll a=p.first,b=p.second;
       if(b>now){
           res+=now*a;
           now=0;
           break;
       }else{
           res+=b*a;
           now-=b;
       }
   }
   cout<<res<<endl;
}