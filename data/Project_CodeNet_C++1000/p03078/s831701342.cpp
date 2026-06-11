#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() 
{
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    
    vector<ll> a(x);
    vector<ll> b(y);
    vector<ll> c(z);
    rep(i,x) cin >> a[i];
    rep(i,y) cin >> b[i];
    rep(i,z) cin >> c[i];

    sort(a.rbegin(), a.rend());
    priority_queue<ll> que;
    rep(i,y)rep(j,z) que.push(b[i]+c[j]);

    int w = min(y*z, 3005);
    vector<ll> d;
    rep(i,w) {
        d.push_back(que.top());
        que.pop();
    }

    priority_queue<ll> Q;
    rep(i,x)rep(j,w) Q.push(a[i]+d[j]);

    rep(i,k){
        cout << Q.top() << endl;
        Q.pop();
    }

    return 0;
}
