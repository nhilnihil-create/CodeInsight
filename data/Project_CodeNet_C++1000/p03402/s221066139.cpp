#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <queue>
#define For(i, n) for(int i = 0; i < (n); i ++)
#define Range(c) c.begin(), c.end()
#define RevRange(c) c.rbegin(), c.rend()
#define Contains(c, x) find(Range(c), x) != c.end()
#define Sort(a) sort(Range(a))
#define DeSort(a) sort(RevRange(a))
#define Vec2(T, n, m, xs, x) vector<vector<T>> xs(n, vector<T>(m, x))
#define Sum(a) accumulate(Range(a), 0)
#define Cusum(T, n, xs, sxs) vector<T> sxs(n+1); For(i, n) sxs[i+1] = sxs[i] + xs[i]
#define Cin(T, x) T x; cin >> x
#define Cins(T, n, xs) vector<T> xs(n); For(i, n) cin >> xs[i]
#define Cins2(T, n, xs, ys) vector<T> xs(n), ys(n); For(i, n) cin >> xs[i] >> ys[i]
#define Cins3(T, n, xs, ys, zs) vector<T> xs(n), ys(n), zs(n); For(i, n) cin >> xs[i] >> ys[i] >> zs[i]
#define Cinss(T, n, m, xs) Vec2(T, n, m, xs, 0); For(i, n) For(j, m) cin >> xs[i][j]
#define Cout(x) cout << (x) << "\n"
#define Couts(xs) for(const auto &e : xs) cout << e << " "; cout << "\n"

using namespace std;
using ll = long long;

int main(void){
    Cin(int, a);
    Cin(int, b);
    
    Vec2(char, 40, 100, c, '#');
    For(i, 20) For(j, 100) c[i][j] = '.';
    
    For(k, a-1){
        int i = (k/50)*2, j = (k%50)*2;
        c[21+i][j] = '.';
    }
    For(k, b-1){
        int i = (k/50)*2, j = (k%50)*2;
        c[i][j] = '#';
    }
    
    Cout("40 100");
    For(i, 40){
        For(j, 100) cout << c[i][j];
        cout << "\n";
    }
}
