#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int M[500][500];
struct Point {
    int y;
    int x;
};
vector<Point> A;
vector<Point> B;

int main() {
    int H, W; cin >> H >> W;
    rep(i, H){
        rep(j, W){
            cin >> M[i][j];
        }
    }
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W-1; j++){
            if(M[i][j] % 2 == 1){
                M[i][j+1]++;
                int y = i+1;
                int x = j+1;
                Point p = {y, x};
                A.push_back(p);
                Point p2 = {y, x+1};
                B.push_back(p2);
            }
        }
    }

    for (int i = 0; i < H-1; i++){
        if(M[i][W-1] % 2 == 1){
            M[i+1][W-1]++;
            int y = i+1;
            int x = W;
            Point p = {y, x};
            A.push_back(p);
            Point p2 = {y+1, x};
            B.push_back(p2);
        }
    }

    int N = A.size();
    cout << N << endl;
    rep(i, N){
        cout << A[i].y << " " << A[i].x << " " << B[i].y << " " << B[i].x << endl;
    }

    return 0;
}