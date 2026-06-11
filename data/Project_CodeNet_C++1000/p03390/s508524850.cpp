#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <set>
#include <complex>

using namespace std;

const int SIZE = 1 << 10;

int pointer = SIZE;
char buffer[SIZE];

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}

const int INF = (1LL << 31) - 1;

long long s;
long long a, b;

bool Ok(long long st, long long dr, long long l, long long r) {
    if (dr <= l)
        return dr * l <= s;
    if (st >= r)
        return st * r <= s;
    double q = 1.0 * (st + r) / 2;
    long long x = q;
    if (1.0 * x == q) {
        if (x * x > s)
            return false;
    }
    else
        if (x * (x + 1) > s)
            return false;
    return true;
}

bool Split(int x, int y, int l, int r) {
    if (y < x || r < l)
        return true;
    if (x <= a && a <= y) {
        int len = a - x;
        return Split(x, x + len - 1, r - len + 1, r) && Split(x + len + 1, y + 1, l, r - len);
    }
    if (l <= b && b <= r) {
        int len = b - l;
        return Split(y - len + 1, y, l, l + len - 1) && Split(x, y - len, l + len + 1, r + 1);
    }
    return Ok(x, y, l, r);
}

bool Check(int x) {
    return Split(1, x, 1, x);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int tests;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        scanf("%lld%lld", &a, &b);
        if (a > b)
            swap(a, b);
        s = a * b - 1;
        long long left = 1, right = INF, answer = 0;
        while (left <= right) {
            long long middle = (left + right) / 2;
            if (Check(middle)) {
                answer = middle;
                left = middle + 1;
            }
            else
                right = middle - 1;
        }
        printf("%lld\n", answer);
    }
    return 0;
}
