#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll MOD = 1000000007;
ll INF =1<<30;
ll dp[110][100100];

bool so(int n){
    if(n==1) return false;
    if(n==2) return true;
    bool ok = true;
    for(int i = 2;i*i<=n;++i){
        if(n%i==0) return  false;
    }
    return  true;
}
int main(){
    int q;
    cin >> q;
    vector<int> ans(100100);
    vector<int> cnt(100100,0);
    for(int i = 1;i<=100010;i++){
        if(so(i)) ans[i]++;
    }
    for(int i = 1;i<=100010;i+=2){
        if(ans[i]&&ans[(i+1)/2])cnt[i]++;
    }
    vector<int> s(100100);
    s[1]=cnt[1];
    for(int i = 1;i<=100010;++i){
        s[i+1] = cnt[i+1]+s[i];
    }
    rep(i,q){
        int l ,r;
        cin >> l >> r;
        cout << s[r]-s[l-1] <<endl;
    }

}
