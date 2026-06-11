#include <bits/stdc++.h>
typedef long long ll;
#define ALL(l)  (l).begin(),(l).end()
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
using namespace std;

//const ll mod =  1000000007;
//const ll maxn = 100000000000000;

//---------------------------------------------------------------------------------------------------
using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vll = vector<ll>; // intの1次元の型に vi という別名をつける
using vvll = vector<vll>; // intの2次元の型に vvi という別名をつける
using vs = vector<string>; // stringの1次元の型に vs という別名をつける
using pll = pair<ll, ll>; // これ以降 pii という型名はpair<ll, ll> と同じ意味で使える
//---------------------------------------------------------------------------------------------------


int main() {
   ll h,w,ans=0;
   cin>>h>>w;
   
   //vvll a(h,vll(w));
   vvll c(10,vll(10));
   rep(i,10){
       rep(j,10)cin>>c.at(i).at(j);
   }
   
   for(int k=0;k<10;k++){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++)c.at(i).at(j)=min(c.at(i).at(j),c.at(i).at(k)+c.at(k).at(j));
    }
}

   rep(i,h){
       rep(j,w){
     
       ll a;
       cin>>a;
       if(a==-1)continue;
       else {
          ans+=c.at(a).at(1);
          // cout<<a<<endl;
       }
       }
   }
   
   cout<<ans<<endl;
   
}

