#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<ll, P> P3;
typedef pair<P ,P> PP;
constexpr ll MOD = ll(1e9) + 7;
constexpr int IINF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
constexpr int MAX_N = int(1e5) + 5;
constexpr double EPS = 1e-8;
constexpr int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define ALL(v) (v).begin(), (v).end()


int main() {
    int k;
    vector<int> dmin;
    cin >> k;
    // bfs
    priority_queue<P, vector<P>, greater<P> > que;
    que.push({1,1});
    dmin.assign(k,IINF);
    dmin[1] = 1;
    while(!que.empty()){
        P p = que.top();
        int now = p.second, d = p.first;
        que.pop();
        if(dmin[now] < d)continue;
        if(dmin[now*10%k] > d){
            dmin[now*10%k] = d;
            que.push({d, now*10%k});
        }
        if(dmin[(now+1)%k] > d + 1){
            dmin[(now+1)%k] = d + 1;
            que.push({dmin[(now+1)%k],(now+1)%k});
        }
    }
    cout << dmin[0] << endl;
    return 0;
}
