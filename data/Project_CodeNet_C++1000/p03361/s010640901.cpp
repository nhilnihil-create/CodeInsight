#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];
    if(h == 1 && w == 1){
        cout << "No" << endl;
        return 0;
    }
    rep(i, 0, h){
        rep(j, 0, w){
            if(s[i][j] == '.') continue;
            bool flag = true;
            rep(dir, 0, 4){
                int ni = i + di[dir], nj = j + dj[dir];
                if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                if(s[ni][nj] == '#') flag = false;
            }
            if(flag){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
