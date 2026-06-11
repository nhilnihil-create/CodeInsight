#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define showmap(is, js, x) {rep(i, is){rep(j, js){cout << x[i][j] << " ";}cout << endl;}}
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> llP;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


bool isdisconnect(vector<vector<int>>& root){
    int n = root.size();
    queue<int> q;
    vector<bool> visited(n, false);
    visited[0] = true;
    q.push(0);

    while(!q.empty()){
        auto now = q.front(); q.pop();
        for (auto next: root[now]){
            if (visited[next]) continue;
            q.push(next); visited[next] = true;
        }
    }

    for(auto x: visited){
        if(!x) return true;
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<P> root_master;
    rep(i, m){
        int a, b; cin  >> a >> b; a--;b--;
        root_master.emplace_back(a,b);
    }
    int ans = 0;
    rep(i, m){
        vector<vector<int>> root(n);
        rep(j, m){
            if (j == i) continue;
            int from = root_master[j].first;
            int to = root_master[j].second;
            root[from].push_back(to);
            root[to].push_back(from);
        }
        ans += isdisconnect(root);
    }
    cout << ans << endl;
}

