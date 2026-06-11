#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e+9;

int main(){
    int n, cnum;
    cin >> n >> cnum;
    int d[30][30];
    for(int i = 0; i < cnum; i++){
        for(int j = 0; j < cnum; j++){
            cin >> d[i][j];
        }
    }
    int cnt[3][30];
    //vector<int, vector<int>> cnt(3, vector<int>(cnum));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int temp;
            cin >> temp;
            cnt[(i+j) % 3][temp-1]++;
        }
    }
    int ans = INF;
    for(int c1 = 0; c1 < cnum; c1++){
        for(int c2 = 0; c2 < cnum; c2++){
            if(c1 == c2) continue;
            for(int c3 = 0; c3 < cnum; c3++){
                if(c1 == c3 || c2 == c3) continue;
                int temp = 0;
                for(int j = 0; j < cnum; j++){
                    temp += cnt[0][j] * d[j][c1];
                }
                for(int j = 0; j < cnum; j++){
                    temp += cnt[1][j] * d[j][c2];
                }
                for(int j = 0; j < cnum; j++){
                    temp += cnt[2][j] * d[j][c3];
                }
                ans = min(ans, temp);
            }
        }
    }
    cout << ans << endl;
    return 0;
}