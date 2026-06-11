#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007LL;
long long GCD(long long a, long long b){return b == 0 ? a : GCD(b, a % b);}
long long fast_exp(long long base, long long exp, long long mod = MOD) {
    long long tot = 1;
    for(;exp > 0;exp >>= 1) {
       if((exp & 1) == 1) tot = tot * base % mod;
       base = base * base % mod;
    }
    return tot;
}

char grid[301][301];

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> grid[i][j];

    long long tot = 0;

    for(int i = 0; i < n; ++i){
        bool f = true;
        char cop[301][301];

        for(int x = 0; x < n; ++x)
            for(int y = 0; y < n; ++y)
                cop[x][y] = grid[x][(y + i) % n];

        for(int x = 0; x < n && f; ++x)
            for(int y = 0; y < n && f; ++y)
                if(cop[x][y] != cop[y][x])
                    f = false;

        if(f)
            tot += n;

    }

    cout << tot << "\n";

    return 0;

}
