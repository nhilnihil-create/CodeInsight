#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

const int INF = 1e9;
const long long LINF = 1e18;
const double PI=3.14159265358979323846;

int main() {
    char b;
    cin >> b;

    map<char, char> m;
    m['A'] = 'T';
    m['C'] = 'G';
    m['G'] = 'C';
    m['T'] = 'A';

    cout << m[b] << endl;

    return 0;
}
