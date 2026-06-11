#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <iomanip>
#include <queue>
#include <map>
#include <list>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX 50
#define LARGENUM 1000000007
#define INF 9223372036854775807
#define ull unsigned long long 
typedef pair <ull, int> P;
char s[MAX][MAX];
int count[MAX][MAX], H, W;

void idou(){
    queue <P> Q;
    rep(i, H){
        rep(j, W) count[i][j] = -1;
    }
    Q.push(P(0, 0));
    count[0][0] = 0;
    P v;
    while (!Q.empty()){
        v = Q.front();
        Q.pop();
        if (v.first + 1 < H && s[v.first + 1][v.second] == '.' && count[v.first + 1][v.second] == -1) {
            Q.push(P(v.first + 1, v.second));
            count[v.first + 1][v.second] = count[v.first][v.second] + 1;
        }
        if (v.first - 1 >= 0 && s[v.first - 1][v.second] == '.' && count[v.first - 1][v.second] == -1) {
            Q.push(P(v.first - 1, v.second));
            count[v.first - 1][v.second] = count[v.first][v.second] + 1;
        }
        if (v.second + 1 < W && s[v.first][v.second + 1] == '.' && count[v.first][v.second + 1] == -1) {
            Q.push(P(v.first, v.second + 1));
            count[v.first][v.second + 1] = count[v.first][v.second] + 1;
        }
        if (v.second - 1 >= 0 && s[v.first][v.second - 1] == '.' && count[v.first][v.second - 1] == -1) {
            Q.push(P(v.first, v.second - 1));
            count[v.first][v.second - 1] = count[v.first][v.second] + 1;
        }
    }
}
int count_white(){
    int count = 0;
    rep(i, H){
        rep(j, W){
            if (s[i][j] == '.') count++;
        }
    }
    return count;
}

int main(){
    cin >> H >> W;
    rep(i, H){
        rep(j, W) cin >> s[i][j];
    }
    idou();
    if (count[H-1][W-1] == -1) {
        cout << -1 << endl;
    }
    else{
        int ans = count_white() - count[H-1][W-1] - 1;
        cout << ans << endl;
    }
    return 0;
}
