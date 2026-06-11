#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
const long long INF = 1LL << 60;
const int INT_INF = 1 << 30;
const double PI = acos(-1.0);

int n;
vi vec = {'3', '5', '7'};
int ans = 0;

void dfs(string x){
    if (x.size() && stoll(x) > n) return;
    bool flag = true;
    if (x.find('3') == string::npos) flag = false;
    if (x.find('5') == string::npos) flag = false;
    if (x.find('7') == string::npos) flag = false;
    if (flag) ans++;

    for (char v: vec){
        dfs(x + v);
    }
    return;
}

int main() {
    cin >> n;
    dfs("");
    cout << ans << endl;

}
