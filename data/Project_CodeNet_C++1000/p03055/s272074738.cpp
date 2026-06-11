#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
const int maxn = 300005;
const int mod = 998244353;
vector<int>g[maxn];
int n;
int dia() {
    int d[n + 5] = {};
    memset(d, -1, sizeof(d));
    queue<int>q;
    q.push(1);
    d[1] = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto i:g[now]) {
            if (~d[i])continue;
            q.push(i);
            d[i] = d[now] + 1;
        }
    }
    int mx = 1;
    f1(n) {
        if (d[i] > d[mx]) {
            mx = i;
        }
    }
    memset(d, -1, sizeof(d));
    //queue<int>q;
    q.push(mx);
    d[mx] = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto i:g[now]) {
            if (~d[i])continue;
            q.push(i);
            d[i] = d[now] + 1;
        }
    }
    mx = 0;
    f1(n) {
        mx = max(mx, d[i]);
    }
    return mx + 1;
}
int main(){
    while(cin >> n){
        f1(n) {
            g[i].clear();
        }
        f (n - 1) {
            int x, y;
            cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }
        int x = dia();
        if (x % 3 == 2) {
            cout << "Second\n";
        }
        else {
            cout << "First\n";
        }
    }
}