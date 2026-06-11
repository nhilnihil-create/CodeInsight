#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define mp make_pair
ll mod = 1000000007;
ll mod2 = 998244353;

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<ll> a(n);
    int ord = 0;
    int zero = 0;
    rep(i,0,n){
        cin>>a[i];
        if (a[i]<0) ord++;
        else if(a[i]==0) zero++;
        a[i] = abs(a[i]);
    }
    ll ans = 0;
    if (zero>0 || ord%2==0){
        rep(i,0,n){
            ans+=abs(a[i]);
        }
        cout<<ans<<endl;
    }else{
        rep(i,0,n){
            ans+=abs(a[i]);
        }
        ans-=*min_element(a.begin(),a.end())*2;
        cout<<ans<<endl;
    }
}