#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include<iomanip>
#include<functional>

using namespace std;
typedef long long ll;

// a と b の最大公約数を返す関数
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
int count2(int n) {
    int ans = 0;
    while (n > 0) {
        if (n % 10 == 2) ans++;
        n /= 10;
    }
    return ans;
}
int main() {
    int N; cin >> N;
    int cnt2 = count2(N);
    cout << cnt2 << endl;
}
