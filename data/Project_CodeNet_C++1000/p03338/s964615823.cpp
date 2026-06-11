#include <algorithm>  // sort, unique
#include <deque>
#include <iostream>  // テスト
#include <string>
#include <vector>

/**
 * 3 2 2 1
 * sort-> 1 2 2 3
 * unique-> 1 2 3 x
 * erase-> 1 2 3
 */
template <typename T>
std::vector<T> deduplicate(std::vector<T> v) {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    return v;
}
/**
 * std::unique は
 * 1. 連続した要素のうち先頭以外の要素を後ろに持っていく
 * 2. 後ろに持っていった要素の値は未規定になる
 * 3. 後ろに持っていった要素の先頭のイテレータを返す
 */
template <typename T>
std::deque<T> deduplicate(std::deque<T> d) {
    std::sort(d.begin(), d.end());
    d.erase(std::unique(d.begin(), d.end()), d.end());
    return d;
}

std::string deduplicate(std::string s) {
    std::sort(s.begin(), s.end());
    s.erase(std::unique(s.begin(), s.end()), s.end());
    return s;
}

// tests----------------------------------------------------------------
void abc098_b();  // stringの重複削除

int main() {
    abc098_b();
    return 0;
}

void abc098_b() {
    using std::string;
    int n;
    std::cin >> n;
    string s;
    std::cin >> s;

    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        string f = deduplicate(s.substr(0UL, i));
        string r = deduplicate(s.substr(i));

        int duplications = 0;
        for (char fc : f) {  // 𝑶(n * n/2 * n/2)
            // find は一致する要素を探してイテレータを返す
            if (r.find(fc) != string::npos) duplications++;
        }
        ans = std::max(ans, duplications);
    }

    std::cout << ans << "\n";
    return;
}