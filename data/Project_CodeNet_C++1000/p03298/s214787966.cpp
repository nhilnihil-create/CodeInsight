#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <map>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <cmath>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;
#define sL(i) i << 1
#define sR(i) i << 1 | 1
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;
typedef pair<string, string> ps;
const int MOD = 1e9 + 7;
const int INF = 2e9 + 5;

int N; 
ll ans = 0;
string S;
map<ps, int> um;

void solve(string s, bool calc = false){
    for (int i = 0; i < (1<<N); i++) {
        string red = "";
        string blue = "";
        for (int j = 0; j < N; j++) {
            if (i & (1<<j)) red += s[j];
            else blue += s[j];
        }
        reverse(blue.begin(), blue.end());
        if (calc) {
            ps x = {blue, red};
            auto it = um.find(x);
            if (it != um.end()) ans += it->second;
        } else {
            ps x = {red, blue};
            um[x]++;
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    cin >> N >> S;
    solve(S.substr(N));
    solve(S.substr(0, N), true);
    cout << ans;
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(t2 - t1).count();
    // cout << "\n";
    // cout << "Ran in " << duration / 1000 << "ms";
}   