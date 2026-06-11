#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;
ll gcd(ll a, ll b){if(b==0) return a; return gcd(b, a%b);}


const int INF=1001001001;

bool func(ll x){
    bool san=false;
    bool nana=false;
    bool go=false;
    while(x>0){
        ll n=x%10;
        if(n==3) san=true;
        if(n==5) go=true;
        if(n==7) nana=true;
        x/=10;
    }
    return san&&go&&nana;
}

int main(){
    fast_io

   ll n;
   cin>>n;

   stack<ll> stk;
   stk.push(0);
   int ans=0;
   while(!stk.empty()){
       ll x=stk.top(); stk.pop();
       if(x*10+3<=n) stk.push(x*10+3);
       if(10*x+5<=n) stk.push(x*10+5);
       if(x*10+7<=n) stk.push(x*10+7);
       if(func(x)){
           ans++;
       }
   }

   cout<<ans<<endl;

    return 0;
}