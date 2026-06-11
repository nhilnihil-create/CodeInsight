#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool used[100005];
vector<int> ki[100005];
int ans[100005];
int N;
int cnt;
void dfs(int now) {
    cnt--;
    ans[now] = cnt;
    for(int x:ki[now]) {
        if(!used[x]) {
            used[x] = true;
            dfs(x);
        }
    }
}
signed main() {
    cin >> N;
    vector<int>a(N-1),b(N-1);
    vector<int>c(N);
    for(int i = 0; i < N-1; i++) {
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
        ki[a[i]].push_back(b[i]);
        ki[b[i]].push_back(a[i]);
    }
    for(int i = 0; i < N; i++) {
        cin >> c[i];
    }
    sort(c.begin(),c.end());
    int M = 0;
    for(int i = 0; i < N-1; i++) {
        M += c[i];
    }
    cnt = N;
    used[0] = true;
    dfs(0);
    cout << M << endl;
    for(int i = 0; i < N; i++) {
        if(i) cout << " ";
        cout << c[ans[i]];
    }
    cout << endl;
}
