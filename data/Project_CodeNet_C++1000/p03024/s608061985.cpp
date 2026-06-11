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
#include <tuple>
using namespace std;
typedef long long ll;
#define REP(i,n) for (int i = 0; i < n; i++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;

int main ()
{
    string s; cin >> s;
    int cnt = 0;
    REP(i,s.size()) if (s[i] == 'o') cnt++;

    int lt = (15 - (int)s.size()) + cnt;
    cout << (lt < 8 ? "NO" : "YES") << endl;

    return 0;
}
