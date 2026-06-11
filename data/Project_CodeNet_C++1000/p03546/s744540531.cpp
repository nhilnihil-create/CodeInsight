#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 100000

typedef long long ll;
typedef pair<int,int> P;

const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const int INF_INT = 1e9;

template<class TYPE>
struct edge{
    TYPE to,cost; 
    edge(TYPE t,TYPE c){
        to = t;
        cost = c;
    }
};

int main(){
    int H,W;
    cin >> H >> W;
    int d[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> d[i][j];
        }
    }
    int a[H][W];
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> a[i][j];
        }
    }
    for(int k = 0; k < 10; k++){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(a[i][j] == -1) continue;
            ans += d[a[i][j]][1];
        }
    }
    cout << ans << endl;
}
