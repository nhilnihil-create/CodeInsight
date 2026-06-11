#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define vv(T) vector<vector<T>>
using namespace std;
using ll = long long;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vbool = vector<bool>;
using vvbool = vector<vector<bool>>;
using qint = queue<int>;
using sint = stack<int>;

const vector<pair<int, int>> MOVELIST = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main(){
    int h, w;
    cin >> h >> w;
    vv(char) a(h);
    queue<pair<int, int>> que;
    rep(i, h){
        // vector<char> tp;
        rep(j, w){
            char ta;
            cin >> ta;
            a[i].push_back(ta);
            // if(ta == '#') que.push(make_pair(j, i));
        }
        // a.push_back(tp);
    }

    vvint times(h, vint (w, -1));
    rep(i, h){
        rep(j, w){
            if(a[i][j] == '#'){
                que.push(make_pair(j, i));
                times[i][j] = 0;
            }
        }
    }

    int ans = 0;
    while(!que.empty()){
        auto tmp = que.front();
        que.pop();
        auto px = tmp.first;
        auto py = tmp.second;
        for(auto next : MOVELIST){
            int nx = px + next.first;
            int ny = py + next.second;
            if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if(a[ny][nx] == '#') continue;
            if(times[ny][nx] != -1) continue;
            que.push(make_pair(nx, ny));
            a[ny][nx] = '#';
            times[ny][nx] = times[py][px] + 1;
        }
        ans = max(ans, times[py][px]);
    }

    cout << ans << endl;
    return 0;
}
