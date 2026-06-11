//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    queue<P> que;
    vvi ch(h, vi(w, -1));
    rep(i, h) {
        cin >> a[i];
        rep(j, w) {
            if(a[i][j] == '#') {
                que.push(P(i, j));
                ch[i][j] = 0;
            }
        }
    }


    while(!que.empty()) {
        int ni = que.front().first;
        int nj = que.front().second;
        que.pop();

        if(ni && ch[ni-1][nj] == -1) {
            ch[ni-1][nj] = ch[ni][nj] + 1;
            que.push(P(ni-1, nj));
        }
        if(nj && ch[ni][nj-1] == -1) {
            ch[ni][nj-1] = ch[ni][nj] + 1;
            que.push(P(ni, nj-1));
        }
        if(ni < h-1 && ch[ni+1][nj] == -1) {
            ch[ni+1][nj] = ch[ni][nj] + 1;
            que.push(P(ni+1, nj));
        }
        if(nj < w-1 && ch[ni][nj+1] == -1) {
            ch[ni][nj+1] = ch[ni][nj] + 1;
            que.push(P(ni, nj+1));
        }

    }

    int ans = 0;
    rep(i, h) {
        rep(j, w) {
            ans = max(ans, ch[i][j]);
        }
    }

    cout << ans << endl;


}