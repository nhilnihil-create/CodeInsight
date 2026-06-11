#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N, M;
    cin >> N;
    set<pair<int,int>> R;
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        R.insert({x,y});
    }
    set<pair<int,int>> B;
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        B.insert({x,y});
    }
/*
    for (auto x : R) {
        printf("%d,%d\n", x.first, x.second);
    }
    cout << endl;
    for (auto x : B) {
        printf("%d,%d\n", x.first, x.second);
    }
*/
   int res = 0;
   for (auto a : B) { 
       bool hit = false;
       pair<int,int> ma = {-1, -1}; // max abcd is 2N = 200
       for (auto b : R) {
           if (a.first <= b.first) break;
           if (a.second > b.second) if (b.second > ma.second) {ma = b; hit = true;} 
       }
       if (hit) {
        R.erase(ma);
        res++;
       }
   }
   cout << res << endl;
}