#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<tuple>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define Per(i,sta,n) for(int i=n-1;i>=sta;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

int n;
string s;
int dp[200010],st[200010];
unordered_map<int,int> ma;

void solve(){
    cin >> s;
    n=s.length();
    rep(i,n){
        int k=(1 << (s[i]-'a'));
        st[i+1]=st[i]^k;
    }
    if (st[n]==0) {
        cout << 1 << endl;
        return;
    }
    ma[0]=0;
    rep(i,n){
        //cout << bitset<26>(st[i+1]) << endl;
        int res=mod;
        if (ma.count(st[i+1])){
            res=ma[st[i+1]];
        }
        else ma[st[i+1]]=mod;
        rep(k,26){
            int m=(1 << k);
            if (ma.count(st[i+1]^m)){
                res=min(res,ma[st[i+1]^m]);
            }
        }
        dp[i+1]=res+1;
        ma[st[i+1]]=min(ma[st[i+1]],dp[i+1]);
        //cout << dp[i+1] << endl;
    }
    cout << dp[n] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}