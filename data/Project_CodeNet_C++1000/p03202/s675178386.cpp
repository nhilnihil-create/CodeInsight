#include <iostream>
#include <vector>

using namespace std;

template <class T>
vector<T> Vec(size_t l, T v) { return vector<T>(l, v); }

template <class T, class... Ts>
auto Vec(size_t l, Ts... ts) {
    return vector<decltype(Vec<T>(ts...))>(l, Vec<T>(ts...));
}

int main() {
    int N;
    cin >> N;
    auto A = Vec<int>(N, 0);
    for (auto& a : A) cin >> a;

    // 答えが1 <=> Aが狭義単調増加
    bool incr = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] >= A[i + 1]) incr = false;
    }
    if (incr) {
        cout << 1 << endl;
        return 0;
    }

    int ok = N, ng = 1;
    while (ok - ng > 1) {
        int K = (ok + ng) / 2;

        vector<pair<int, int>> word;
        int L = 0;
        for (auto a : A) {
            if (L >= a) {
                while (!word.empty() && word.back().first > a) word.pop_back();
                word.push_back(make_pair(a + 1, K));
            }
            L = a;

            // 繰り上がり処理
            while (!word.empty() && word.back().second == K) {
                int l = word.back().first;
                word.pop_back();
                if (!word.empty() && word.back().first == l - 1) {
                    ++word.back().second;
                } else {
                    word.push_back(make_pair(l - 1, 1));
                }
            }
        }

        if (word.front().first > 0) {
            ok = K;
        } else {
            ng = K;
        }
    }

    cout << ok << endl;
    return 0;
}
