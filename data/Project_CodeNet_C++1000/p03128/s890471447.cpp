#include<bits/stdc++.h>
#define Rushia_mywife ios::sync_with_stdio(0);cin.tie(0);
#define rep(i,head,n) for(int i=(head);i<n;i++)
#define int long long
#define F first
#define S second
#define pb push_back
#define p2(n) (1<<(n))
#define lg2(n) __lg(n)
using namespace std;
using pii = pair<long long,long long>;
using ld = long double;
mt19937 mt_rand(time(0));
const int mod = 1000000007;
const int hnum = 998244353;
const ld PI = acos(-1);

int n,m;
int val[10] = {0,2,5,5,4,5,6,3,7,6};
int a[10];
string ans;
string dp[10010];

string maxstr(string x,string y){
    if(x.size()==y.size())
        return max(x,y);
    return (x.size()>y.size() ? x : y);
}

void solve(){
    cin >> n >> m;
    rep(i,0,m){
        cin >> a[i];
        dp[val[a[i]]] = maxstr(dp[val[a[i]]],dp[0]+char(a[i]+'0'));
    }
    rep(i,1,n+1)
        rep(j,0,m)
            if(val[a[j]]<=i&&dp[i-val[a[j]]]!="")
                dp[i] = maxstr(dp[i],dp[i-val[a[j]]]+char(a[j]+'0'));
    cout << dp[n] << '\n';
}

signed main(){
    Rushia_mywife
    solve();
}