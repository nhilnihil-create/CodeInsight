// #pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define String std::string
#define fir first
#define sec second
#define mp std::make_pair
#define Pair std::pair<int, int>
#define Map std::map< int, int >
#define Vector std::vector<int>

typedef long long ll;
typedef unsigned long long ull;

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };
const int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };

inline ll read() {
    ll res = 0, f = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
    for (; isdigit(ch); ch = getchar()) res = (res << 1) + (res << 3) + ch - '0';
    return res * f;
}

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;
    if ((b - a) & 1) puts("Borys");
    else puts("Alice");
    return 0;
}