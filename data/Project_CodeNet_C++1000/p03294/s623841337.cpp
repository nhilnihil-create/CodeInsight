#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;

int main() {
    int n;
    cin >> n;
    ll ans = 0;
    rep(i, 0, n) {
        int tmp;
        cin >> tmp;
        ans+= tmp-1;
    }
    cout << ans << endl;
}