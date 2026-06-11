#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int INF = 100000;
void chmin(int &a, int b) { if (a > b) a = b; }

int N, A, B, C;
vector<int> L;

// 再帰
int rec(int i, int a, int b, int c) {
    if (i == N) {
        if (!a || !b || !c) return INF; // A, B, C いずれも竹は 1 本は必ず使ってないとダメ
        return abs(a - A) + abs(b - B) + abs(c - C); // 合体してできた a, b, c を A, B, C にするコスト
    }

    // 今ある竹を採用しない場合
    int res = rec(i+1, a, b, c);
    
    // A, B, C を使う場合。
    // (a ? 10 : 0) とかは、最初の 1 本目は合体コストなし、2 本目からはコスト 10 かかることを意味する
    chmin(res, rec(i+1, a + L[i], b, c) + (a ? 10 : 0));
    chmin(res, rec(i+1, a, b + L[i], c) + (b ? 10 : 0));
    chmin(res, rec(i+1, a, b, c + L[i]) + (c ? 10 : 0));
    
    return res;
}

int main() {
    // 入力
    cin >> N >> A >> B >> C;
    L.resize(N);
    for (int i = 0; i< N; ++i) cin >> L[i];
    
    // 再帰する
    cout << rec(0, 0, 0, 0) << endl;
}