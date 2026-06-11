#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(v) v.begin(), v.end()
#define ll long long
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<long long>;
using vvll = vector<vll>;

//snippets:tmp,cl,cvl,cs,co,coy,con,cov

int main(){
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    ll count=m*1900+(n-m)*100;
    ll a=1;
    rep(i,m) a*=2;
    cout<<count*a<<endl;
}