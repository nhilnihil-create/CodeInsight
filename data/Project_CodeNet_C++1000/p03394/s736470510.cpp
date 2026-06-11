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
const int MOD = 1e9 + 7;
const int INF = 9e18;

signed main() {
    int N;
    cin >> N;
    if (N == 3) {
        cout << "2 5 63" << endl;
        return 0;
    }
    if (N == 4) {
        cout << "2 5 20 63" << endl;
        return 0;
    }
    if (N == 5) {
        cout << "2 3 4 6 9" << endl;
        return 0;
    }
    set<int> ans;
    auto temp = [](int now) {
        int m = now / 4;
        int d = now % 4;
        if (d == 0) return m * 6;
        else if (d == 1) return m * 6 + 2;
        else if (d == 2) return m * 6 + 3;
        else if (d == 3) return m * 6 + 4;
    };
    for (int i = 1; i <= N; i++) {
        ans.insert(temp(i));
    }
    int num = accumulate(ans.begin(), ans.end(), 0LL);
    int six = (N + 1) / 4 + 1;
    if (num % 6 == 2) {
        ans.erase(8);
        ans.insert(six * 6);
    } else if (num % 6 == 3) {
        ans.erase(9);
        ans.insert(six * 6);
    } else if (num % 6 == 5) {
        ans.erase(9);
        if ((N + 1) % 4 != 3) --six;
        ans.insert(6 * six + 4);
    }
    auto itr = ans.begin();
    for (int i = 0; i < N; i++) cout << (*itr++) << (i == N - 1 ? '\n' : ' ');
}
