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

int sum[400010];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    string S; cin >> S;
    vector<int> v;
    int len = 0;
    if(S[0] == '1') v.push_back(0);
    rep(i, N) {
        if(i == 0 || S[i - 1] == S[i]) len++;
        else {
            v.push_back(len);
            len = 1;
        }
    }
    if(len > 0) v.push_back(len);
    int ans = 0;
    int res = 0;
    int right = 0;
    int cnt = 0;
    for(int left = 0; left < v.size(); left++) {
        while(right < v.size() && (right % 2 == 0) + cnt <= K) {
            res += v[right];
            cnt += (right % 2 == 0);
            ++right;
        }
        //cout << left << " " << right << " " << cnt << " " << res << endl;
        ans = max(ans, res);
        if(left == right) right++;
        else {
            cnt -= (left % 2 == 0);
            res -= v[left];
        }
    }
    cout << ans << endl;


    return 0;
}
// 0 