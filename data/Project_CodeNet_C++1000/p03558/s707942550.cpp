#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

const int INF = 1001001001;

void YN(bool flg){if(flg) cout << "YES" << endl; else cout << "NO" << endl;}
void Yn(bool flg){if(flg) cout << "Yes" << endl; else cout << "No" << endl;}
void yn(bool flg){if(flg) cout << "yes" << endl; else cout << "no" << endl;}

struct Edge
{
    int to;
    int cost;
};

int k;

vector<vector<Edge>> g(114514);

void dijkstra() {
    vi d(k, INF);
    d[1] = 1;

    // int 型の要素を持ち、最も小さい値を取り出す形の priority_queue を定義する場合
    priority_queue<P, vector<P>, greater<P>> q;
    q.push(P(1, 1));

    while(!q.empty()) {
        P p = q.top(); q.pop();
        int v = p.first;
        if(d[v] < p.second) continue;
        for(auto e : g[v]) {
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                q.push(P(e.to, d[e.to]));
            }
        }
    }

    cout << d[0] << endl;
}

int main() {
    cin >> k;
    rep(i, k) {
        if(i != k-1) g[i].push_back(Edge{i+1, 1});
        else g[i].push_back(Edge{0, 1});
        if((i * 10) % k != i) g[i].push_back(Edge{(i * 10) % k, 0});
    }

    /*
    rep(i, k) {
        cout << i << ": " << endl;
        for(auto j : g[i]) {
            cout << j.to << " " << j.cost << endl;
        }
    }
    */

    dijkstra();
    
    return 0;
}
