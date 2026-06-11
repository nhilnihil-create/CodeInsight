#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

int main(){
   int X;cin>>X;
   int ans=1;
   rep(num,2,X){
       int now=num*num;
       while(now<=X){
           ans = max(ans,now);
           now = now*num;
       }
   }
   cout<<ans<<endl;
}
