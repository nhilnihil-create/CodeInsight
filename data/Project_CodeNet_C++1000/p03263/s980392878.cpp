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
typedef pair<ll,ll> pll;
typedef pair<pll,pll> ppll;
const int INF = 1e9+100;
const ll INF64 = 7e18l;
const int mod = 1000000007;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(), (a).end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);



int main(){
    FIN;
    ll h,w;
    cin >> h >> w;
    vector<vector<int>> a(h,vector<int>(w,0));
    int odd = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> a[i][j];
            if(a[i][j]%2 == 1) odd++;
        }
    }

    vector<ppll> res;
    int num = 0;
    int x = 0, y = 0;
    for(int itr = 0;itr < h*w; itr++){
        if(a[x][y] %2 == 1) num++;

        int nx = x, ny = y;
        if(x%2 == 0){
            if(ny == w-1) nx++;
            else ny++;
        }else{
            if(ny == 0) nx++;
            else ny--;
        }
        if(num%2 == 1) if(num < odd) res.push_back(ppll(pll(x,y),pll(nx,ny)));
        x = nx;
        y = ny;
    }

    cout << res.size() << endl;
    for(auto p : res){
        cout << p.first.first+1;
        cout << " ";
        cout << p.first.second+1;
        cout << " ";
        cout << p.second.first+1;
        cout << " ";
        cout << p.second.second+1 << endl;
    }

    return 0;
}

