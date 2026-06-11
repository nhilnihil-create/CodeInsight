#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<ll, ll>;
#define debug(var) cout << "[" << #var << "] " << var << endl
const ll mod = 1000000007;


int main(){
    int n, k;
    cin >> n >> k;
    vector<P> s(n);
    rep(i, n) {
        cin >> s[i].first >> s[i].second;
        s[i].first--;
    }
    auto comp = [](P a, P b) {
        if (a.second!=b.second) return a.second>b.second;
        else return a.first<b.first;
    };
    sort(s.begin(), s.end(), comp);
    priority_queue<P, vector<P>, decltype(comp)> q{comp};
    vector<ll> num(n);
    ll sum = 0;
    ll nt = 0;
    rep(i, k) {
        q.push(s[i]);
        if (num[s[i].first]==0) nt++;
        num[s[i].first]++;
        sum += s[i].second;
    }
    ll ans = nt*nt + sum;

    

    for (int i=k; i<n; i++) {
        if (num[s[i].first]) continue;
        P now = P(-1, 0);
        while (!q.empty()) {
            now = q.top();
            q.pop();
            if (num[now.first]>1) break;
        }
        if (q.empty() || now.first==-1) break;
        sum -= now.second;
        sum += s[i].second;
        nt++;
        num[s[i].first]++;
        ans = max(ans, sum+nt*nt);
    }
    
    
    
    cout << ans << endl;
    return 0;
}
