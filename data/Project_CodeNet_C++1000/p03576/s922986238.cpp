#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include <cassert>
#include <cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()


using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;



int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> x(n), y(n);
    vector<P> p;
    rep(i, n){
        cin >> x[i] >> y[i];
        p.emplace_back(x[i], y[i]);
    }
    sort(ALL(x));
    sort(ALL(y));
    ll res = INF * INF * 100;
    for(int lx = 0; lx < n; lx++){
        for(int rx = lx + 1; rx < n; rx++){
            for(int ly = 0; ly < n; ly++){
                for(int ry = ly + 1; ry < n; ry++){
                    int cnt = 0;
                    for(int now = 0; now < n; now++){
                        if(x[lx] <= p[now].first && p[now].first <= x[rx] && y[ly] <= p[now].second && p[now].second <= y[ry])cnt++;
                    }
                    if(cnt >= k){
                        res = min(res, (ll)((x[rx] - x[lx]) * (y[ry] - y[ly])));
                    }
                }
            }
        }
    }
    cout << res << endl;
}
