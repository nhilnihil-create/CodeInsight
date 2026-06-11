#include <bits/stdc++.h>
 
using namespace std;

using usize = ::std::size_t;
using u64 = ::std::int_least64_t;
//using u64 = int;
static constexpr u64 Inf = ::std::numeric_limits<u64>::max() / 2;

u64 n, E;
u64 H, W;
u64 d[10][10], w[10][10];
bool negative_cycle = false;

void floydWarshall(){
    for (int i = 0; i <= 9; i++){
        for (int j = 0; j <= 9; j++){
            d[i][j] = w[i][j];
        }
    }
    for (int k = 0; k <= 9; k++){
        for (int i = 0; i <= 9; i++){
            for (int j = 0; j <= 9; j++){
                if(d[i][k] == Inf || d[k][j] == Inf) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    return;
}

int main(int argc, char *argv[])
{
    // input from txt （提出時にこの箇所は削除すること）
    //ifstream in("in.txt");
    //cin.rdbuf(in.rdbuf());
 
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    //cin >> n >> E;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            cin >> w[i][j];
        }
    }
    
    
    floydWarshall();
    u64 total = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int a;
            cin >> a;
            if(a == -1) continue;
            else total += d[a][1];
        }
    }
    
    cout << total << endl;
    
    return 0;
}
