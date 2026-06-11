#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

ll gcd(ll x,ll y) {return y ? gcd(y,x%y) : x;}
ll lcm(ll x, ll y) {return x/gcd(x,y)*y;}



int main(){
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    rep(i,n){
        int a;
        cin>>a;
        v[i]=abs(a-x);
    }

    if(n==1){
        cout<<v[0]<<endl;
        return 0;
    }

    int ans=gcd(v[0],v[1]);
    for(int i=2;i<n;i++) ans=gcd(ans,v[i]);

    cout<<ans<<endl;
}

