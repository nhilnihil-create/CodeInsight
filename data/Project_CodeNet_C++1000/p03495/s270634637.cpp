#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
   int n,k;cin>>n>>k;
   map<int,int> mp;
   rep(i,n){
       int a;cin>>a;
       mp[a]++;
   }
   int x=mp.size();
   priority_queue<int, vector<int>, greater<int> > que;
   for(auto& p:mp){
       que.push(p.second);
   }
   int res=0;
   rep(i,x-k){
       int a=que.top();que.pop();
       res+=a;
   }
   cout<<res<<endl;
}