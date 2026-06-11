#include <iostream>
#include <functional>

struct Closed_Section {
    bool valid;
    int64_t begin;
    int64_t end;
    Closed_Section(bool _valid, int64_t _begin, int64_t _end) {
        valid = _valid; begin = _begin; end = _end;
    }
    Closed_Section() {
        valid = false, begin = 0; end = -1; //配列を定義するためにデフォルトコンストラクタが必要。
    }
    int64_t size() { return valid ? end - begin + 1 : 0; }
    void dump() { std::cout << "valid:" << valid << " begin:" << begin << " end:" << end << std::endl; }
};

Closed_Section binary_search(const int64_t L, const int64_t R, std::function<bool(int64_t)> func) {
    if (R < L) { return Closed_Section(false, L, R); }
    const bool res_L = func(L);
    const bool res_R = func(R);
    if (res_L && res_R) {
        return Closed_Section(true, L, R);
    } else if (!res_L && !res_R) {
        return Closed_Section(false, 0, -1);
    } else {
        int64_t lb = L;
        int64_t ub = R;
        while (lb + 1 < ub) {
            int64_t mid = (lb + ub) / 2;
            if (res_L == func(mid)) {
                lb = mid;
            } else {
                ub = mid;
            }
        }
        return res_L ? Closed_Section(true, L, lb) : Closed_Section(true, ub, R);
    }
}

Closed_Section binary_search(const Closed_Section& cs, std::function<bool(int64_t)> func) {
    return cs.valid ? binary_search(cs.begin, cs.end, func) : cs;
}

// end of template

int64_t N, Q;
std::string s;
const int64_t MAX_Q = 2e5 + 10;
char t[MAX_Q], d[MAX_Q];

int64_t calc(int64_t pos) {
    for (int64_t i = 1; i <= Q; i++) {
        if (t[i] == s[pos]) {
            if (d[i] == 'L') {
                pos--;
            } else {
                pos++;
            }
            if (pos == 0 || pos == N+1) {
                return pos;
            }
        }
    }
    return pos;
}

int main(int argc, char **argv) {
    std::cin >> N >> Q;
    std::cin >> s;
    s = "!" + s;
    for (int64_t i = 1; i <= Q; i++) {
        std::cin >> t[i] >> d[i];
    }
    auto cs = binary_search(1, N, [&](int64_t i){
        return 1 <= calc(i);
    });
    cs = binary_search(cs, [&](int64_t i){
        return calc(i) <= N;
    });
    std::cout << cs.size() << std::endl;
}