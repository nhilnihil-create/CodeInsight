#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#include <iomanip>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};
int INF = 2e6;
ll MOD = 1e9 + 7;

int main() {
    int n, x; cin >> n >> x;
    vector<int> m(n);
    int sum = 0;
    rep(i,n) {
        cin >> m[i];
        sum += m[i];
    }
    sort(m.begin(),m.end());

    cout << (x - sum) / m[0] + n << endl;
}
