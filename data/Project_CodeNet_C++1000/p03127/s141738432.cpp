#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(a%b==0)return b;
    return gcd(a%b,b);
}

int main(){
    int N;cin>>N;
    vector<int>A(N);
    rep(i,N){
        cin>>A.at(i);
    }
    ll ans=A.at(0);
    for(int i=0;i<N;i++){
        ans=gcd(A.at(i),ans);
    }
    cout<<ans<<endl;


}
