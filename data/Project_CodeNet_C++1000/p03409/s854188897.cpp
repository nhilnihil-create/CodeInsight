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
#include <cmath>
#include <iomanip> //cout << fixed << setprecision(15) << << endl;
#include <cassert>
//#include "atcoder/all"

using namespace std;
//using namespace atcoder;

typedef long long ll;

#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define P pair<int,int>

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
ll mod = 1000000007;


int main(){
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<pair<int,int>> red(n),blue(n);
    rep(i,n) cin >> red[i].first >> red[i].second;
    rep(i,n) cin >> blue[i].second >> blue[i].first;
    sort(red.rbegin(),red.rend());
    sort(blue.begin(),blue.end());

    int ans = 0;
    vector<bool> b(n,false);

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(red[i].first < blue[j].second && red[i].second < blue[j].first && !b[j])
            {
                b[j] = true;
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}