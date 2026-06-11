#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <numeric>
#include <bits/stdc++.h>

#define int long long

struct edge {
    int to;
    int cost;
};

using namespace std;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vb = vector<bool>;
using qi = queue<int>;
using P = pair<int, int>;
using graph = vector<vector<edge>>;
// using graph = vector<vector<int>>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define delim(i, n) cout << (i == n-1 ? "\n" : " ");

const int inf = 1LL << 60;
// const int inf = 100000000;
const int mod = 1000000007;

const int maxn = 100001;
int n;
vi visited(maxn);

bool isPrime(int n) {
    if (n == 2 || n == 3) return true;
    if (n == 1 || n%2 == 0 || n%3 == 0) return false;
    int sn = sqrt(n);
    int divisor = 5;
    while(divisor <= sn) {
        if (n%divisor == 0) return false;
        if (n%(divisor+2) == 0) return false;
        divisor += 6;
    }
    return true;
}

signed main () {
	cin.tie(0);
   	ios::sync_with_stdio(false);

    visited.assign(maxn, 0);
    set<int> prime;
    vi like(maxn, 0);

    prime.insert(2);
    prime.insert(3);
    like[3] = 1;
    for(int i = 5; i < maxn; i+=2) {
        bool flag = isPrime(i);
        if (flag) prime.insert(i);
        if (flag && prime.count((i+1)/2)) like[i] = 1;
    }

    vi likesum(maxn, 0);
    REP(i, maxn-1) {
        likesum[i+1] = likesum[i] + like[i];
    }

    cin >> n;
    REP(i, n) {
        int l, r; cin >> l >> r;
        cout << likesum[r+1] - likesum[l] << "\n";
    }
}