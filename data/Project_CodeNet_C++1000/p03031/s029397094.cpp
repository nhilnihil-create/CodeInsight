#include <bits/stdc++.h>
typedef long long ll;
#define ALL(l)  (l).begin(),(l).end()
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

//const ll mod =  1000000007;
//const ll maxn = 1000000000;

//---------------------------------------------------------------------------------------------------
using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vll = vector<ll>; // intの1次元の型に vi という別名をつける
using vvll = vector<vll>; // intの2次元の型に vvi という別名をつける
using vs = vector<string>; // stringの1次元の型に vs という別名をつける
using pll = pair<ll, ll>; // これ以降 pii という型名はpair<ll, ll> と同じ意味で使える
//---------------------------------------------------------------------------------------------------

int main() {
   int n,m;
   cin>>n>>m;
   vvll s(m,vll(10,0));
   rep2(i,0,m){
       int k;
       cin>>k;
       rep(j,k){
           int ss;
           cin>>ss;
           s.at(i).at(ss-1)=1;
       }
   }
   vll p(m,0);
   rep2(i,0,m)cin>>p.at(i);
   
   int ans=0;
   
   
   for (int tmp = 0; tmp < (1 << n); tmp++) {
    bitset<10> k(tmp);  
    bool allright=true;
    rep(i,m){
        int sum=0;
        rep(j,10){
            if(s.at(i).at(j)==1){
                if(k.test(j))sum++;
            }
        }
        //cout<<i<<" "<<sum<<endl;
        if(!(sum%2==p.at(i))){
            allright=false;
            break;
        }
    }
    if(allright)ans++;
    //cout<<endl;
    }
  cout<<ans<<endl;

}

