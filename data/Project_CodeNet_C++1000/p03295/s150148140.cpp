#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    int M; cin >> M;
    vector<pair<int, int> > B;
    rep(i, M){
        int a, b; cin >> a >> b;
        B.push_back(make_pair(a, b));
    }
    sort(B.begin(), B.end());

    queue<pair<int, int> > Q;
    int now = 0;
    rep(i, M){
        if(B[i].first != now){
            Q.push(B[i]);
            now = B[i].first;
        }
    }

    pair<int, int> p2 = Q.front(); Q.pop();
    int l = p2.first;
    int r = p2.second;
    int ans = 1;

    while(!Q.empty()){
        pair<int, int> p = Q.front(); Q.pop();
        if(r <= p.first){
            ans++;
            l = p.first;
            r = p.second;
        } else {
            l = max(l, p.first);
            r = min(r, p.second);
        }
    }
    cout << ans << endl;

    return 0;
}