#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <functional>
#include <cmath>
#include <numeric>
#include <iomanip>
#define REP(i,n) for(lint i{}, i##_len=(n); i<i##_len; ++i)
#define DREP(i, h, j, w) for(lint i{}; i < (lint)(h); ++i)for(lint j{}; j < (lint)(w); ++j)
#define DREP2(i, j, n) for(lint i{}; i < (lint)(n - 1); ++i)for(lint j{i + 1}; j < (lint)(n); ++j)
#define SZ(x) ((lint)(x).size())
using lint = long long; lint N, M, H, W;
using namespace std;
const long long INF{ 1LL << 60 };
const long double PI{ 3.1415926535897932 };
const long long NUM97{ 1000000007 };
//動的計画法
template<class T> inline bool chmax(T& x, T y) { if (x < y) { x = y; return 1; } return 0; }
template<class T> inline bool chmin(T& x, T y) { if (x > y) { x = y; return 1; } return 0; }
std::vector<std::string> field;
std::vector<std::vector<bool>> seen(H, std::vector<bool>(W));
//マス上の操作ハンドル(0 < i < 4)でループ回して用いる。
const std::vector<int> dx{ 1, 0, -1, 0 };
const std::vector<int> dy{ 0, 1, 0, -1 };
//pair型vectorの整列。sortの第三因数に指定して用いる。
bool first_larger(std::pair<lint, lint>& a, std::pair<lint, lint>& b) {
    if (a.first != b.first) return{ a.first > b.first };
    else return { a.second > b.second };
}
bool second_smaller(std::pair<lint, lint>& a, std::pair<lint, lint>& b) {
    if (a.second != b.second) return{ a.second < b.second };
    else return { a.first < b.first };
}
bool second_larger(std::pair<lint, lint>& a, std::pair<lint, lint>& b) {
    if (a.second != b.second) return{ a.second > b.second };
    else return { a.first > b.first };
}
//素数判定
bool is_prime(lint N) {
    if (N == 1) return false;
    for (lint i = 2; i * i <= N; ++i) { if (N % i == 0) return false; }
    return true;
}
//char&string → int
lint toInt(char c) {
    return (lint)(c - '0');
}
lint StoInt(std::string s) { lint num{};
    for (int i = 0; i < s.size(); ++i) { if (i > 0) num *= 10; num += (lint)(s[i] - '0');}
    return num;
}
//桁数取得
lint get_digit(lint n) {
    return log10(n) + 1;
}
//階乗
lint factorial(lint n) { lint sum = 1;
    for (int i = 1; i <= n; ++i) sum *= i;
    return sum;
}
//組み合わせの数
lint combination(lint a, lint b) {
    lint ans{ 1 }, ta{ a }, tb{ b };
    while (ta > a - b) ans *= ta; --ta;
    while (tb > 0) ans /= tb; --tb;
    return ans;
}
//約数カウント
lint count_divisors(lint N) { lint count{};
    for (lint i = 1; i * i <= N; ++i) {
        if (N % i == 0) { ++count; if (N / i != i) ++count; } } 
    return count;
}
lint count_prime_divisors(lint N) { lint count{};
    for (lint i = 1; i * i <= N; ++i) {
        if (N % i == 0) {  if (is_prime(i))  ++count; 
            if (N / i != i) { if (is_prime(N / i))  ++count; } } }
    return count;
}
//約数列挙
std::vector<lint> divisors(lint N) { std::vector<lint> divisor;
    for (lint i = 1; i * i <= N; ++i) {
        if (N % i == 0) { divisor.push_back(i);
            if (N / i != i) divisor.push_back(N / i); }
    } std::sort(divisor.begin(), divisor.end());
    divisor.erase(std::unique(divisor.begin(), divisor.end()), divisor.end());
    return divisor;
}
//素因数列挙
std::vector<lint> prime_divisors(lint N) { std::vector<lint> p_divisor;
    for (lint i{ 1 }; i * i <= N; ++i) {
        if (N % i == 0) { if (is_prime(i)) { p_divisor.push_back(i); }
            if (N / i != i) { if (is_prime(N / i)) { p_divisor.push_back(N / i); } } }
    } std::sort(p_divisor.begin(), p_divisor.end());
        p_divisor.erase(std::unique(p_divisor.begin(), p_divisor.end()), p_divisor.end());
    return p_divisor;
}
//素因数分解(first: 素因数, second: 各要素の数)
std::vector<std::pair<lint, lint>> prime_factorize(lint N) {
    vector<pair<lint, lint>> factorize;
    for (lint a{ 2 }; a * a <= N; ++a) {
        if (N % a != 0) continue;
        lint ex{ 0 };
        while (N % a == 0) { ++ex; N /= a; }
        factorize.push_back({ a, ex }); }
    if (N != 1) factorize.push_back({ N, 1 });
    return factorize;
}
//DIVIDE
void divide(lint N, lint& a, lint& b) {
    if (N % 2 == 1) { a = N / 2 + 1; b = N / 2; }
    else { a = N / 2; b = N / 2; }
}

/*=================Competitive programming=====================*/
/*=======================TEMPLATES=============================*/

string func(lint a) {
    string s = "";
    lint p = get_digit(a);
    REP(i, 6 - a) s.push_back('0');
    string ss = std::to_string(a);
    s += ss;
    return s;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    vector<int>P(M), Y(M); vector<vector<int>>D(N);
    for (int i = 0; i < M; ++i) { cin >> P.at(i) >> Y.at(i);
        D.at(P.at(i) - 1).emplace_back(Y.at(i));
    }
    for (int i = 0; i < N; ++i) {
        sort(D.at(i).begin(), D.at(i).end());
    }
    for (int i = 0; i < M; ++i) {
        cout << setfill('0') << setw(6) << P.at(i)
            << setfill('0') << setw(6) <<
            lower_bound(D.at(P.at(i) - 1).begin(), D.at(P.at(i) - 1).end(), Y.at(i)) - D.at(P.at(i) - 1).begin() + 1 << endl;
    }

}