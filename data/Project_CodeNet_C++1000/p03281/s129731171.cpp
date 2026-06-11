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
int nyakusu(int x){
    int ans=1;
    rep2(i,2,x+1){
        int j=0;
        while(1){
            if(x%i!=0)break;
            x/=i;
            j++;
        }ans*=(j+1);
    }
    return ans;
}

int main() {
    vi a(201,0);
    int n;
    cin>>n;
    rep2(i,1,201){
        if(i%2==1&&nyakusu(i)==8)a.at(i)++;
    }
    //rep2(i,1,201)cout<<i<<" "<<nyakusu(i)<<endl;
    rep2(i,2,201)a.at(i)+=a.at(i-1);
    cout<<a.at(n)<<endl;
}

