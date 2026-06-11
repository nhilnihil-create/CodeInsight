#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)
using ll = long long;
using pll = pair<ll,ll>;
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
using vstr = vector<string>;
const ll MOD=1000000007;
vll dx{0,1,0,-1};
vll dy{1,0,-1,0};
int i,j,k,n,m,a,b,c;
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
    cin >> n >> k;
    if (k % 2 == 0) {
        ll a = n / k; 
        ll b = (n + (k/2)) / k;
        cout << a*a*a + b*b*b << endl;
    }
    else {
        ll a = n / k;
        cout << a*a*a << endl;
    }
}

int main(){
    solve();
    return 0;
}