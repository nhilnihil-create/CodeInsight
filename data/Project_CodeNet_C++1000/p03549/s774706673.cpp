#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <queue>
#include <climits>
#include <set>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ve vector
#define umap unordered_map
#define iter iterator

void solve() {
    int n,m;
    cin>>n>>m;
    int p = 1 << m;
    int t = m*1900 + (n-m)*100;
    cout << t*p << endl;
}

int main() {
    solve();
    return 0;
}