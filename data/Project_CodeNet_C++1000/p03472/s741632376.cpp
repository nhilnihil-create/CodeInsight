#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for (int i = s; i < (int)(n); i++)
using ll = long long;
using pll = pair<ll,ll>;
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
using vstr = vector<string>;
const ll MOD=1000000007;
vll dx{0,1,0,-1};
vll dy{1,0,-1,0};
int i,j,k,h,n,m,a,b,c;
ll res,ans;

template <class type> void printVector(vector<type> vec){
    stringstream ss;
    ll n=vec.size();
    for(ll i=0;i<n;i++)
    {
        ss<<vec[i]<<" ";
        if(i!=n-1)ss<<" ";
    }
    cout<<ss.str()<<endl;
}

template <class type> void inputVector(vector<type>& vec){
    for(ll i=0;i<vec.size();i++)
    {
        cin>>vec[i];
    }
}

void solve(){
    ll h;
    cin >> n >> h;
    vll b(n);
    ll ma=0;
    rep(i,0,n){
        ll a;cin>>a>>b[i];
        ma=max(a,ma);
    }
    sort(b.rbegin(),b.rend());
    res=0;
    for(i=0;ma<b[i];i++)
    {
        h-=b[i];
        res++;
        if(h<=0)break;
    }
    if(0<h)res+=ceil((double)h/ma);
    cout<<res;
}

int main(){
    solve();
    return 0;
}