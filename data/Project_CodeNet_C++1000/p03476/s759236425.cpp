#include <bits/stdc++.h>

typedef long long ll;
#define ALL(l)  (l).begin(),(l).end()
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define pb push_back
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

bool sosu(int x){
    rep2(j,2,sqrt(x)+1){
        if(x%j==0)return false;
    }
    return true;
}

int main() {
    vi a(100001,0);
    vi b(100001);
    for(int i=3;i<100001;i+=2){
        if(sosu(i)&&sosu((i+1)/2)){
            a.at(i)=1;
        }
    }
    int k=0;
    rep(i,100001){
        k+=a.at(i);
        b.at(i)=k;
    }
    /*
    rep2(i,2,2018){
        cout<<i<<" "<<a.at(i)<<endl;
    }
    */
    
    int n;
    cin>>n;
    rep(i,n){
        int l,r,ans=0;
        cin>>l>>r;
        /*
        rep2(i,l,r+1){
            if(i==1)continue;
            if(i%2==0)continue;
            if(i!=3&&((i+1)/2)%2==0)continue;
            if(sosu(i)&&sosu((i+1)/2)){
                //cout<<i<<endl;
                ans++;
            }
        }*/
        
        cout<<b.at(r)-b.at(l-1)<<endl;
    }
    
}