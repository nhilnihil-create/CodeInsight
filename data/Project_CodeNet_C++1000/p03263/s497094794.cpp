#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int a[505][505];

int main()
{
    int h, w;
    cin >> h >> w;
    
    int odd = 0;
    rep(i,h)rep(j,w) {
        cin >> a[i][j];
    }

    vector<vector<int>> V;

    int step = 0;
    int y = 0;
    int x = 0;
    while (true) {
        step++;
        if (step == w*h) break;

        int next_x, next_y;
        if (y % 2 == 0) { // 偶数行
            next_x = x==w-1? x : x+1;
            next_y = x==w-1? y+1 :y;
        } else {          // 奇数行
            next_x = x==0? 0 : x-1;
            next_y = x==0? y+1 : y;
        }

        if (a[y][x] % 2 == 1) {
            a[y][x]--;
            a[next_y][next_x]++;
            vector<int> v = {y, x, next_y, next_x};
            V.push_back(v);
        }
        
        x = next_x;
        y = next_y;
    }

    cout << V.size() << endl;
    rep(i,V.size()) {
        auto v = V[i];
        cout << v[0]+1 << " " << v[1]+1 << " " << v[2]+1 << " " << v[3]+1 << endl;
    }

    return 0;
}