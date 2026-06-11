#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
    string s; cin >> s;
    ll n = s.size();

    ll cnt = 0,b = 0;
    rep(i,n) {
        if(s[i] == 'B') {
            cnt += n - i - 1;
            b++;
        }
    }

    cout << cnt - b * (b - 1) / 2 << endl;
}
