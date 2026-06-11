#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

int sum[400020];
vector<int> v;
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    string S; cin >> S;
    if(S[0] == '0') v.push_back(0);
    int len = 0;
    rep(i, S.length()) {
        if(len == 0 || S[i - 1] == S[i]) len++;
        else if(i + 1 == S.length() || S[i - 1] != S[i]) {
            v.push_back(len);
            len = 1;
        }
    }
    v.push_back(len);
    rep(i, v.size()) sum[i + 1] += sum[i] + v[i];
    rep(i, 400000) sum[i + 1] = max(sum[i + 1], sum[i]);
    int ans = 0;
    rep(i, 50010) {
        ans = max(ans, sum[i * 2 + 1 + K * 2] - sum[i * 2]);
    }
    cout << ans << endl;

    return 0;
}
