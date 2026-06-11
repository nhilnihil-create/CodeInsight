#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
typedef long long ll;
using namespace std;
int main(void){
   int n,k;cin>>n>>k;
   map<ll,ll> mp;
   priority_queue<pair<ll,ll>> que;
   priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > que2;
   rep(i,n){
       ll x,t;cin>>x>>t;
       que.push({t,x});
   }
   ll res1=0,st=0;
   rep(i,k){
       auto p=que.top();que.pop();
       ll t=p.second,d=p.first;
       res1+=d;
       if(mp[t]!=0){
           mp[t]++;
           que2.push({d,t});
       }else{
           mp[t]++;
       }
   }
   st=mp.size();
   //cout<<res1<<" "<<st<<endl;
   ll res=res1+st*st;
   while(que.size()&&que2.size()){
       auto p=que.top();que.pop();
       ll t=p.second,d=p.first;
       if(mp[t]!=0)continue;
       auto p2=que2.top();que2.pop();
       ll t2=p2.second,d2=p2.first;
       //cout<<res1+(d-d2)+(st+1)*(st+1)<<endl;
        st++;
        mp[t]--;
        mp[t2]++;
        res1+=(d-d2);
        res=max(res,res1+st*st);
   }
   //cout<<res1<<" "<<st<<endl;
   cout<<res<<endl;
}