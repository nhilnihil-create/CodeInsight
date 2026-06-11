#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>

#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define PI 3.141592653589
#define MOD 1000000007

using namespace std;

const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void solve_75B(){
    int h, w;
    cin >> h >> w;
    char s[h][w];
    int ans[h][w];
    REP(i,h){
        REP(j, w){
            cin >> s[i][j];
            ans[i][j] = 0;
            if(s[i][j] == '#') ans[i][j] = -1;
        }
    }

    REP(i,h){
        REP(j,w){
            if(s[i][j] == '#') continue;
            REP(k, 8){
                if(i + dx[k] < 0 || i + dx[k] >= h || j + dy[k] < 0 || j + dy[k] >= w) continue;

                if(s[i + dx[k]][j + dy[k]] == '#') ans[i][j]++;
            }
        }
    }

    REP(i,h){
        REP(j,w){
            if(ans[i][j] < 0) cout << '#';
            else cout << ans[i][j];
        }
        cout << endl;
    }
    
}

int main(void){
    solve_75B();
    
    return 0;
}