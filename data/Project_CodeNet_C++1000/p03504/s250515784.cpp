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

struct info {
    int s, t, c;
};

signed main() {
    int N, C;
    cin >> N >> C;
    vector<info> program(N);
    for (int i = 0; i < N; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        program[i] = {s, t, c};
    }
    auto sorting = [](info a, info b) {
        return a.s < b.s;
    };
    sort(program.begin(), program.end(), sorting);
    vector<vector<info>> recorder;
    for (auto temp : program) {
        bool addCheck = false;
        for (auto & i : recorder) {
            auto last = *(i.end() - 1);
            if (last.c == temp.c) {
                if (last.t <= temp.s) {
                    i.push_back(temp);
                    addCheck = true;
                    break;
                }
            } else {
                if (last.t < temp.s) {
                    i.push_back(temp);
                    addCheck = true;
                    break;
                }
            }
        }

        if (!addCheck) {
            recorder.push_back({temp});
        }
    }
    cout << recorder.size() << endl;
}
