#include <bits/stdc++.h>
using namespace std;

#define H 50
#define W 50

int h, w;
char s[H+2][W+2];

int main(void)
{
    cin >> h >> w;
    int cntWhite = 0;
    int dist[H+2][H+2];
    for (int i = 0; i <= h+1; i++){
        for (int j = 0; j <= w+1; j++){
            dist[i][j] = -1;
            s[i][j] = '#';
        }
    }

    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++){
            cin >> s[i][j];
            if (s[i][j] == '.'){
                cntWhite++;
            }
        }
    }

    queue<int> searchCoor;
    searchCoor.push(1);
    searchCoor.push(1);
    dist[1][1] = 1;
    while (searchCoor.empty() == false && dist[h][w] == -1){
        int nowH = searchCoor.front(); searchCoor.pop();
        int nowW = searchCoor.front(); searchCoor.pop();
        for (int j = -1; j < 3; j++){                           // sin, cos内部の値が大きいと誤差で正確な値がでない...
            int nextH = nowH + sin(0.5*j*M_PI);
            int nextW = nowW + cos(0.5*j*M_PI);
            if (s[nextH][nextW] == '.' && dist[nextH][nextW] == -1){
                searchCoor.push(nextH);
                searchCoor.push(nextW);
                dist[nextH][nextW] = dist[nowH][nowW] + 1;
            }
        }
    }

    int ans = ( (dist[h][w] == -1) ? -1 : cntWhite - dist[h][w] );
    cout << ans << endl;

    return 0;
}
