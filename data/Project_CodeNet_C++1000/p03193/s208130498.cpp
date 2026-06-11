#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

int main()
{
    ll n,h,w;
    cin>>n>>h>>w;
    ll cnt=0;
    rep(i,n){
        ll a,b;
        cin>>a>>b;
        if(a>=h&&b>=w)cnt++;
    }
    cout<<cnt<<endl;
}