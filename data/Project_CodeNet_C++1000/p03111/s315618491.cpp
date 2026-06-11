#include <bits/stdc++.h>
 using namespace std;
 using pii = pair<int, int>;
 using ll = long long;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;
 const ll INFL = 1LL << 60;
 const int INFI = (1 << 30);

 int N, A, B, C;
 vector<int> L;

 int rec(int i, int a, int b, int c) {
     if (i == N) {
         if (a == 0 || b == 0 || c == 0) return INFI; // A, B, C いずれも竹は 1 本は必ず使ってないとダメ
         return abs(a - A) + abs(b - B) + abs(c - C); // 合体してできた a, b, c を A, B, C にするコスト
     }
     int res = rec(i + 1, a, b, c);
     res = min(res, rec(i + 1, a + L.at(i), b, c) + (a ? 10 : 0));
     res = min(res, rec(i + 1, a, b + L.at(i), c) + (b ? 10 : 0));
     res = min(res, rec(i + 1, a, b, c + L.at(i)) + (c ? 10 : 0));
     return res;
 }
 int main() {
     cin >> N >> A >> B >> C;
     L.resize(N);
     for (int i = 0; i < N; i++) cin >> L.at(i);
     cout << rec(0, 0, 0, 0) << endl;
 }
