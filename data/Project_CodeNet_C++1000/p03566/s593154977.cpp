#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9+ 7;
const int INF = 2e18;

signed main() {
    int N;
    cin >> N;
    vector<double> v(N), t(N);
    cin >> t >> v;
    auto calc = [](double v0, double t, double a) {
        return v0 * t + 0.5 * a * t * t;
    };
    double ans = 0, now = 0;
    for (int i = 0; i < N; i++) {
        for(double j = 0; j < t[i]; j += 0.5) {
            bool check = true, temp = true;
            double next = t[i] - j - 0.5;
            for (int k = i + 1; k < N; k++) {
                next += t[k];
                if(now + 0.5 - next > v[k + 1]) check = false;
                if(now - v[k + 1] > next) temp = false;
            }
            if(now + 0.5 <= v[i] && check && (now + 0.5 - (t[i] - j - 0.5)) <= v[i + 1]) {
                ans += calc(now, 0.5, 1);
                now += 0.5;
            } else if(now - v[i + 1] <= t[i] - j - 0.5 && temp) {
                ans += now * 0.5;
            } else {
                ans += calc(now, 0.5, -1);
                now -= 0.5;
            }
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
}
