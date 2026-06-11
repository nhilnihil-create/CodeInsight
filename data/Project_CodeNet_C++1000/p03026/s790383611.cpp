#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int v[100005];

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> c(n);
    int ans[n];
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int sum = 0;
    rep(i,n){
        cin >> c[i];
        sum += c[i];
    }
    sort(ALL(c),greater<>());
    int cnt = 0;
    queue<int> q;
    q.push(0);
    v[0] = 1;
    ans[0] = c[cnt];
    sum -= ans[0];
    cnt++;
    while(!q.empty()){
        int now = q.front();q.pop();
        for(int i=0;i<g[now].size();i++){
            int next = g[now][i];
            if(v[next])continue;
            v[next] = 1;
            ans[next] = c[cnt];
            cnt++;
            q.push(next);
        }
    }
    cout << sum << endl;
    rep(i,n)cout << ans[i] << " ";
    cout << endl;
}