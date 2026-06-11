#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using ll = long long;
using ld = long double;
using namespace std;
const int INF = 1e9+100;
const ll INF64 = 7e18l;
const int mod = 1000000007;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(), (a).end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main(){
    FIN;
    int H,W; cin >> H >> W;
    int h,w; cin >> h >> w;

    vector<vector<bool>> a(H,vector<bool>(W,false));
    for(int i=0;i<h;i++){
        for(int j=0;j<W;j++){
            a[i][j] = true;
        }
    }
    for(int i=0;i<w;i++){
        for(int j=0;j<H;j++){
            a[j][i] = true;
        }
    }

    int ans = 0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(!a[i][j]) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}

