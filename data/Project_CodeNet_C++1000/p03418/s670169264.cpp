#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
using vstr = vector<string>;

vstr islands(10);
vvll seen(10, vll(10, -1));
vll dx{0, 1, 0, -1};
vll dy{1, 0, -1, 0};

int main()
{
    ll n,k,res;
    cin>>n>>k;
    res = 0;
    for(ll b=k+1;b<=n;b++){
        res+=(n/b)*(b-k);
        for(ll i=1;i<=n%b;i++){
            if(k<=i)res++;
        }
    }
    cout<<res;
    return 0;
}