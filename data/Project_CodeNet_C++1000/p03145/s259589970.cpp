#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;
ll gcd(ll a, ll b){if(b==0) return a; return gcd(b, a%b);}
int main(){
    fast_io

    int x, y, z;
    cin>>x>>y>>z;
    cout<<x*y/2<<endl;

    return 0;
}