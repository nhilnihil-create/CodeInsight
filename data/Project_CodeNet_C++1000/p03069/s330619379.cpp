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

int main(){
    int n;cin >> n;
    string s;
    cin >> s;
    vector<int>black(n),white(n);
    int b = 0,w=0;
    rep(i,n){
        if(s[i]=='#') b++;
        black[i]=b;
        if(s[i]=='.') w++;
        white[i]=w;
    }
    if(b==0||w==0){
        cout << 0 <<endl;
        return 0;
    }
    int ans = min(b,w);
    rep(i,n){
        int cnt = 0;
        cnt +=black[i];
        cnt +=w-white[i];
        ans = min (ans,cnt);
    }
    cout << ans <<endl;
}