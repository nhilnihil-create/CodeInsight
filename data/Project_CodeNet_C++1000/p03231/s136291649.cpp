#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

long long gcd(long long m,long long n){
    if(n==0){
        return m;
    }
    return gcd(n,m%n);
}
 
long long lcm(long long a,long long b){
    long long g=gcd(a,b);
    return a/g*b;
}


int main(){
    ll n,m;
    string s,t;
    cin>>n>>m>>s>>t;
    ll g=gcd(n,m);
    ll ans=lcm(n,m);

    for(ll i=0;i<g;i++){
        if(s[i*n/g]!=t[i*m/g]){
            cout<<-1<<endl;
            return 0;
        }
    }

    cout<<ans<<endl;
}