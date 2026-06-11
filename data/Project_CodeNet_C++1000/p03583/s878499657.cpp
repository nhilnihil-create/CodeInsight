    #include <bits/stdc++.h>
    using namespace std;
    #define int long long
    #define PI 3.141592653589793
    #define rep(i, n) for (int i = 0; i < (n); i++)
    #define rrep(i, n, k) for (int i = (n); i >= (k); i--);
    #define all(x) (x).begin(), (x).end()
    template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
    template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
    template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
    template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
    const int inf = 2e17;
    const int mod = 1e9 + 7;

    signed main() {
        double N;
        cin >> N;
        for (double h = 1; h <= 3500; ++h) {
            for (double n = 1; n <= 3500; ++n) {
                double w = (N * h * n) / (4 * h * n - N * n - N * h);
                if (w == ceil(w) && w > 0 && w <= 3500) {
                    cout << h << " " << n << " " << w;
                    return 0;
                }
            }
        }

    }

