#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
using namespace std;
using ll = long long;
using vl = vector<long long>;
using vs = vector<string>;
using vcc = vector<vector<char>>;
using vll = vector<vector<long long>>;
using vm = vector<short>;
using vmm = vector<vector<short>>;
int main() {
    ll n, m;
    cin >> n >> m;
    vll data(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> data[i][j];
        }
    }
    pair<int, int> p;
    pair<int, int> q;
    ll count = 0;
    vll dataa(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dataa[i][j] = data[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == n - 1 && j == m - 1) {
            }
            else {
                if (dataa[i][j] % 2 == 1) {
                    if (i == n - 1) {
                        dataa[i][j+1]++;
                        count++;
                    }
                    else {
                        dataa[i + 1][j]++;
                        count++;
                    }
                }
            }
        }
    }
    cout << count << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (data[i][j] % 2 == 1) {
                p.first = i + 1;
                p.second = j + 1;
                if (i != n - 1) {
                    data[i + 1][j]++;
                    q.first = i + 2;
                    q.second = j + 1;
                }
                else {
                    if (j != m - 1) {
                        data[i][j + 1]++;
                        q.first = i + 1;
                        q.second = j + 2;
                    }
                    else {
                    }
                }
                if (i == n - 1 && j == m - 1) {
                }
                else cout << p.first << " " << p.second << " " << q.first << " " << q.second << endl;
            }
        }
    }
}