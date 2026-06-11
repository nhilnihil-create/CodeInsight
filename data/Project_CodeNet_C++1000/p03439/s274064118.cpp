#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstdint>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

bool check(int i, int male0, string sex) {
    if(sex == "Male" && male0 == true && i % 2 == 0)
        return true;
    if(sex == "Female" && male0 == true && i % 2 == 1)
        return true;
    if(sex == "Male" && male0 == false && i % 2 == 1)
        return true;
    if(sex == "Female" && male0 == false && i % 2 == 0)
        return true;
    return false;
}

int main() {
    int N;
    cin >> N;
    int l = 0, r = N;
    cout << 0 << "\n" << flush;
    string S;
    cin >> S;
    int male0 = 0;
    if(S == "Vacant")
        return 0;
    else if(S == "Male")
        male0 = 1;
    while(1) {
        int mid = (l + r) / 2;
        cout << mid << "\n" << flush;
        string s;
        cin >> s;
        if(s == "Vacant") {
            return 0;
        }
        if(check(mid, male0, s)) {
            l = mid;
        } else
            r = mid;
    }
    return 0;
}