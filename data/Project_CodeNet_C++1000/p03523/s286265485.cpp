#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <regex>
#include <set>
#include <string>
#include <vector>
#define SORT(a) sort(a.begin(), a.end())
#define RSORT(a) sort(a.rbegin(), a.rend())
#define REP(i, n) for (int i = 0; i < n; i++)
#define RREP(i, n) for (int i = n; 0 <= i; i--)
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define FORSTEP(i, start, end, step) for (int i = start; i < end; i += step)
#define RFOR(i, start, end) for (int i = start; end <= i; i--)
#define ALL(a) a.begin(), a.end()
#define MOD(a) a %= 1000000007
typedef long long ll;
using namespace std;
template <class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    string ans = s;

    vector<string> akiba = {"AKIHABARA", "AKIHBAR",  "AKIHABR",  "AKIHBR",
                            "AKIHABRA",  "AKIHBARA", "AKIHBARA", "KIHABARA",
                            "KIHABAR",   "KIHABR",   "KIHBR",    "KIHBRA",
                            "KIHABRA",   "KIHBARA",  "KIHBAR",   "AKIHABAR"};

    REP(i, akiba.size()) {
        if (s == akiba[i]) {
            std::cout << "YES" << std::endl;
            return 0;
        }
    }

    std::cout << "NO" << std::endl;
    return 0;
}