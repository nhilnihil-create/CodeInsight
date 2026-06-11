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
typedef pair <int, int> P;

int main(){
    int H, W, D, a, Q, L, R;
    cin >> H >> W >> D;
    P p[H * W + 1];
    int Distance[H * W + 1];
    for (int i = 1; i <= H; i++){
        for (int j = 1; j <= W; j++){
            cin >> a;
            p[a] = P(i, j);
        }
    }
    for (int k = 1; k <= D; k++){
        Distance[k] = 0;
        int I = k;
        while(I + D <= H * W){
            Distance[I + D] = Distance[I] + abs(p[I].first - p[I + D].first) + abs(p[I].second - p[I + D].second);
            I += D;
        }
    }
    cin >> Q;
    rep(i, Q){
        cin >> L >> R;
        cout << Distance[R] - Distance[L] << endl;
    }
    return 0;
}
