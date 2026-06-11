#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cassert>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

struct pos {
    double x, y;
    pos(double x, double y):x(x), y(y) {}
};

struct line {
    double slope, intercept;
    line(double slope, double intercept):slope(slope), intercept(intercept) {}
    double getX(double y) {
        return slope * (y - intercept);
    }
    double getY(double x) {
        return slope * x + intercept;
    }
    static pos getCrossPos(line l1, line l2) {
        double x = (l2.intercept - l1.intercept) / 2;
        double y = (l1.intercept + l2.intercept) / 2;
        return {x, y};
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<double> T(N), V(N);
    for (auto& t : T) {
        cin >> t;
    }
    for (auto& v : V) {
        cin >> v;
    }
    V.push_back(0);
    vector<double> cumsum(N, 0);
    rep(i, 0, N) {
        cumsum[i] = T[i] + (i ? cumsum[i - 1] : 0);
    }
    vector<line> L;
    rep(i, 1, N + 1) {
        L.emplace_back(-1, V[i] + cumsum[i - 1]);
    }
    double elapsed = 0;
    double now_v = 0;
    double ans = 0;
    rep(i, 0, N) {
        int idx = -1;
        line now(1, now_v - elapsed);
        double last_x = elapsed + T[i];
        double max_v = now.getY(last_x);
        rep(j, i, N) {
            pos cross_pos = line::getCrossPos(now, L[j]);
            if (cross_pos.x <= last_x && chmin(max_v, cross_pos.y)) {
                idx = j;
            }
        }
        if (idx < 0) {
            double x = last_x;
            if (chmin(max_v, V[i])) {
                x = now.getX(V[i]);
            }
            ans += (x - elapsed) * (now_v + max_v) / 2;
            ans += (last_x - x) * max_v;
            now_v = max_v;
        } else {
            double x1 = line::getCrossPos(now, L[idx]).x;
            double x2 = x1;
            double next_v = L[idx].getY(last_x);
            if (chmin(max_v, V[i])) {
                x1 = now.getX(V[i]);
                x2 = L[idx].getX(V[i]);
                if (chmin(x2, last_x)) {
                    next_v = V[i];
                }
            }
            ans += (x1 - elapsed) * (now_v + max_v) / 2;
            ans += (x2 - x1) * max_v;
            ans += (last_x - x2) * (max_v + next_v) / 2;
            now_v = next_v;
        }
        elapsed += T[i];
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}