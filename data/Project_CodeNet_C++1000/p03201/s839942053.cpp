#include <iostream>
#include <fstream>
#include <set>
#include <unordered_map>
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

unordered_map<int, int> mp;
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int A[200010];
    rep(i, N) {
        cin >> A[i];
        mp[A[i]]++;
    }
    int num = (1 << 30);
    int ans = 0;
    rep(k, 31) {
        rep(i, N) {
            int remain = num - A[i];
            if(remain <= 0) continue;
            if(remain != A[i] && mp[remain] > 0 && mp[A[i]] > 0) {
                ans++;
                mp[remain]--;
                mp[A[i]]--;
                //cout << remain << " " << A[i] << endl;
            } else if(remain == A[i] && mp[A[i]] > 1) {
                ans++;
                mp[A[i]] -= 2;
                //cout << remain << " " << A[i] << " " << mp[A[i]] << endl;
            }
        }
        num >>= 1;
        //cout << num << endl;

    }
    cout << ans << endl;

    return 0;
}
