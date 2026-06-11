#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i,n){
        cin >> h[i];
    }
    sort(h.begin(),h.end());
    int ans = h[k-1] - h[0];
    for(int i=0;i<=n-k;i++){
        int diff = h[i+k-1]-h[i];
        ans = min(ans, diff);
    }
    cout << ans << endl;
}