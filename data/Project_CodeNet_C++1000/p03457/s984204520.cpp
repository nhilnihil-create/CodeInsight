#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;
#define ODD 1
#define EVEN 0

signed main() {
    int n;
    cin >> n;
    vector<vi> table(n, vi(3));
    rep(i, n){
        rep(j, 3){
            cin >> table[i][j];
        }
    }

    int now_x = 0, now_y = 0, now_time = 0;

    bool can_travel = true;

    rep(i, n){
        int diff = abs(now_x - table[i][1]) + abs(now_y - table[i][2]);
        int diff_time = table[i][0] - now_time;
        now_x = table[i][1];
        now_y = table[i][2];
        now_time = table[i][0];
        if(diff > diff_time) can_travel = false;
    }

    now_x = 0, now_y = 0, now_time = 0;
    int cur = ODD, mukasi = EVEN;
    rep(i, n){
        if((table[i][0] - now_time)%2 == ODD && abs((now_x+now_y)-table[i][1]+table[i][2])%2 == EVEN) can_travel = false;
        if((table[i][0] - now_time)%2 == EVEN && abs((now_x+now_y)-table[i][1]+table[i][2])%2 == ODD) can_travel = false;
        now_x = table[i][1];
        now_y = table[i][2];
        now_time = table[i][0];
    }

    if(can_travel) cout << "Yes" << endl;
    else cout << "No" << endl;
}