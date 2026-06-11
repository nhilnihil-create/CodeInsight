#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int N, A, B, C;
vector<int> L(8);
int DFS(int cur, int a, int b, int c) {
    if (cur == N) {
        if (min({a,b,c}) == 0) return 1<<30;
        else return abs(A-a) + abs(B-b) + abs(C-c) - 30;
    }
    int r0, r1, r2, r3;
    r0 = DFS(cur + 1, a, b, c);
    r1 = DFS(cur + 1, a + L[cur], b, c) + 10;
    r2 = DFS(cur + 1, a, b + L[cur], c) + 10;
    r3 = DFS(cur + 1, a, b, c + L[cur]) + 10;
    int r4 = min({r0, r1, r2, r3});
    //printf("%d %d %d %d: %d\n", cur, a, b, c, r4);
    return r4;

}

int main() {
    cin >> N >> A >> B >> C;
    rep(i,N) cin >> L.at(i);
    cout << DFS(0, 0, 0, 0) << endl; 
}