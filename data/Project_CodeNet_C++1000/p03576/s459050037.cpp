#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const ll mod = 1000000007;
const int inf = 1e9;
const long long INF = 1LL << 60;

int main()
{
    int n,k;
    cin >> n >> k;
    vector<pair<ll,ll> > v;
    for(int i = 0; i < n; i++){
        ll x,y;
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }
    ll ans = 4e18;
    for(int xi = 0; xi < n; xi++){
        for(int xj = xi + 1; xj < n; xj++){
            for(int yi = 0; yi < n; yi++){
                for(int yj = yi + 1; yj < n; yj++){
                    ll minx,maxx,miny,maxy;
                    vector<ll> xlist;
                    vector<ll> ylist;

                    if(v[xi].first < v[xj].first){
                        minx = v[xi].first;
                        maxx = v[xj].first;
                    }else{
                        minx = v[xj].first;
                        maxx = v[xi].first;
                    }
                    if(v[yi].second < v[yj].second){
                        miny = v[yi].second;
                        maxy = v[yj].second;
                    }else{
                        miny = v[yj].second;
                        maxy = v[yi].second;                        
                    }
                    ll tmp = (maxx - minx) * (maxy - miny);
                    int cnt = 0;
                    bool ok = false;
                    for(int k = 0; k < n; k++){
                        if(minx <= v[k].first && v[k].first <= maxx && miny <= v[k].second && v[k].second <= maxy) cnt++;
                    }
                    if(k <= cnt) ok = true;
                    if(ok){
                        if(ans > tmp) ans = tmp;
                    }
                }
            }
        }
    }
    cout << ans;
}
