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
    int ans=0;
    vi a(10,0);
    string s;
    cin>>s;
    rep(i,s.size()){
        if(s.at(i)=='A'||s.at(i)=='C'||s.at(i)=='G'||s.at(i)=='T'){
            a.at(i)=1;
        }
    }
    rep2(i,1,10){
        if(a.at(i)==1)a.at(i)+=a.at(i-1);
    }
    rep(i,10){
        ans=max(ans,a.at(i));
    }
    cout<<ans<<endl;
    
}