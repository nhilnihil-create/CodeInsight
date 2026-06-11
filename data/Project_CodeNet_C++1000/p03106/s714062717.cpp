#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    ll a,b,k,tmp=0; cin>>a>>b>>k;
    for(int i=min(a,b); i>=1; i--){
        if(a%i==0 && b%i==0) tmp++;
        if(tmp==k){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}