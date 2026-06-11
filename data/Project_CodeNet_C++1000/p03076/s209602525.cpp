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

int main() {
    vector<int> A(5);
    for (int i = 0; i < 5; i++) cin >> A[i];
    vector<int> P = { 0,1,2,3,4 };
    int ans = 1e9;
    do {
        int num = 0;
        for (int i = 0; i < 5; i++) {
            while (num % 10 != 0) num++;
            num += A[P[i]];
        }
        ans = min(num, ans);
    } while (next_permutation(P.begin(), P.end()));
    cout << ans << endl;
}
