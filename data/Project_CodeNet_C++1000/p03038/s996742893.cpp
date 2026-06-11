#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n, m;
    cin >> n >> m;
    
    priority_queue<int,vector<int>,greater<int>> pq;
    rep(i,n) {
        int a;
        cin >> a;
        pq.push(a);
    }
    
    vector<P> cb(m);
    rep(i,m) cin >> cb[i].second >> cb[i].first;
    
    sort(cb.rbegin(),cb.rend());
    
    rep(i,m) {
        while(pq.top() < cb[i].first && cb[i].second > 0) {
            pq.pop();
            pq.push(cb[i].first);
            cb[i].second--;
        }
    }
    
    ll ans = 0;
    rep(i,n) {
        ans += pq.top();
        pq.pop();
    }
    
    cout << ans << endl;
    
    
    return 0;
}
