
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <numeric>
#include <deque>
#include <cstring>
#include <iterator>
#include <map>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <complex>
#include <bitset>
#include <chrono>
#include <random>
#include <assert.h>
#include <array>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define mn(x) *min_element((x).begin(),(x).end())
#define mx(x) *max_element((x).begin(),(x).end())
#define acc(x) accumulate((x).begin(),(x).end(),0ll)
#define eb emplace_back
#define el '\n'
typedef  long long  ll;
typedef  unsigned long long  ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

const ld pi=acos(-1);
const ll inf=(ll)1e12+1;
const int mod=1000000007;
//const int mod=998244353;

int n,m,k;
const int N=3e5+10;






int main()
{   ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> m;
    vvi vv(n,vi(m));
    vector<array<int,4>> ans;
    auto f = [&](int row){
        if(row==n-1){
            for(int i=0; i<m-1; i++){
                if(vv[row][i]&1){
                    vv[row][i]--;
                    vv[row][i+1]++;
                    ans.pb({row+1,i+1,row+1,i+2});
                }
            }
        }
        else{
            for(int i=0; i<m; i++){
                if(vv[row][i]&1){
                    vv[row][i]--;
                    vv[row+1][i]++;
                    ans.pb({row+1,i+1,row+2,i+1});
                }
            }
        }
    };
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int u;
            cin >> u;
            vv[i][j]+=u;
        }
        f(i);
    }
    cout << ans.size() << el;
    for(auto it: ans){
        cout << it[0] << ' ' << it[1] << ' ' << it[2] << ' ' << it[3] << el;
    }
    return 0;
}




