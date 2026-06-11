#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n,m;
    cin >> n >> m;
    priority_queue<pair<ll,ll>>q;
    rep(i,n) {
        int a;
        cin >> a;
        q.push(make_pair(a,1));
    }
    rep(i,m) {
        ll b,c;
        cin >> b >> c;
        q.push(make_pair(c,b));
    }
    ll ans = 0;
    rep(i,n) {
        auto p = q.top();q.pop();
        ans += p.first;
        p.second--;
        if(p.second > 0) q.push(p);
    }
    cout << ans << endl;

}