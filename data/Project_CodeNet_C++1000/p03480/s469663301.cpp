#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
typedef long long ll;

int main ()
{
    string S; cin >> S;

    if (S.size() == 1) {
        cout << 1 << endl;
        return 0;
    }

    int n = (int)S.size();
    int ans = n;
    REP(i,S.size() - 1) {
        if (S[i] != S[i + 1]) {
            ans = min(ans, max(i + 1, n - 1 - i));
        }
    }

    cout << ans << endl;

    return 0;
}
