#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define RREP(i, n) for(int (i)=(n)-1; (i)>=0; (i)--)
#define ios() cin.tie(0), ios::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
ll const MOD = 1e9+7;
ll const INF = 1e18;
using namespace std;

int main(){
    const int n = 100;
    int a, b;
    cin >> a >> b;
    vector<vector<char>> grid(n, vector<char>(n, '.'));
    REP(i, n/2) REP(j, n) grid[i][j] = '#';

    int x = 1, y = 1;
    REP(i, a-1){
        grid[x][y] = '.';
        y += 2;
        if(y > n-2){
            x += 2;
            y = 1;
        }
    }
    x = n/2+1, y = 1; 
    REP(i, b-1){
        grid[x][y] = '#';
        y += 2;
        if(y > n-2){
            x += 2;
            y = 1;
        }
    }

    cout << n << " " << n << endl;
    REP(i, n){
        REP(j, n){
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}