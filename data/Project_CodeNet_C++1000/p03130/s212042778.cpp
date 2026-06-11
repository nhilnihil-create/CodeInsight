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
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;

const int D = 60;
const int max_n = 200005;



int main() {
    vector<vector<int>> g(4);
    rep(i,3){
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    int one = 0, two = 0;
    rep(i,4){
        if(g[i].size() == 1) one++;
        else if(g[i].size() == 2) two++;
    }
    if(one == 2 && two == 2) cout << "YES" << endl;
    else cout << "NO" << endl;
}


