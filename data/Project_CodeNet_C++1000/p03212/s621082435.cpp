#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};
int INF = 2e6;
ll MOD = 1e9 + 7;
int cnt = 0;
ll n;
/*vector<string> p;

void dfs(ll a) {
    if(a <= n) {
        cnt++;
        p.pb(to_string(a));


    if(a * 10 + 3 <= n) dfs(a * 10 + 3);
    if(a * 10 + 5 <= n) dfs(a * 10 + 5);
    if(a * 10 + 7 <= n) dfs(a * 10 + 7);
    }   
}


int main(){
    cin >> n;
    int ans = 0;
    dfs(0);
    for(int i = 0;i < cnt;i++){
        int si = p[i].size();
        string s = p[i];
        bool ok3 = false, ok5 = false, ok7 = false;
        for(int j = 0;j < si;j++){
            if(s[j] == '3') ok3 = true;
            if(s[j] == '5') ok5 = true;
            if(s[j] == '7') ok7 = true;
        }
        if(ok3 && ok5 && ok7) ans++;
    }
    cout << ans << endl;
}
*/

void dfs(ll a, bool ok3, bool ok5, bool ok7){
    if(a <= n && ok3 && ok5 && ok7) cnt++;

    if(a * 10 + 3 <= n) dfs(a * 10 + 3, true, ok5, ok7);
    if(a * 10 + 5 <= n) dfs(a * 10 + 5, ok3, true, ok7);
    if(a * 10 + 7 <= n) dfs(a * 10 + 7, ok3, ok5, true);
}

int main(){
    cin >> n;
    dfs(0, false, false, false);
    cout << cnt << endl; 
}
