#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <string>
#include <numeric>
#include <stack>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i, a, N) for(int i = a; i < N; i++)

int main() {
    int N, H, W;
    cin >> N >> H >> W;
    cout << (N - H + 1) * (N - W + 1) << endl;
}