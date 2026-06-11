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
#include <numeric>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;

ll y[10000005];

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;


    vector<int> z, o;
    if (s[0] == '0') o.pb(0);
    int t = 0, cnt = 0;
    while (t < n) {
        if (s[t] == s[t + 1]) {
            t++;
            cnt++;
        } else {
            cnt++;
            if (s[t] == '0') z.pb(cnt);
            else o.pb(cnt);
            t++;
            cnt = 0;
        }
    }
    if(s[n-1] == '0') o.pb(0);

    if(k > z.size()){
        cout << n << endl;
        return 0;
    }

    int zsum = 0, osum = 0, ans = 0, Sum = 0;
    for(int i = 0; i < k; i++) zsum += z[i];
    for(int i = 0; i < k+1; i++) osum += o[i];
    for(int i = 0; i < o.size() - k - 1; i++){
        Sum = zsum + osum;
        ans = max(ans,Sum);
        zsum -= z[i];
        zsum += z[i+k];
        osum -= o[i];
        osum += o[i+k+1];
    }
    ans = max(ans,zsum + osum);
    cout << ans << endl;
}