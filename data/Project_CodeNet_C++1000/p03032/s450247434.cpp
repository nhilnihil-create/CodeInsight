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
    vector<ll> v(n);
    rep(i, n)cin >> v[i];
    ll res = 0;
    rep(i, n + 1){
        for(int j = n - 1; j >= -1; j--){
            if(i - j > 1)continue;
            ll sum = 0;
            vector<ll> list(1, INF);
            rep(k, i){
                sum += v[k];
                if(v[k] < 0)list.push_back(v[k]);
            }

            for(int l = n - 1; l > j; l--){
                sum += v[l];
                if(v[l] < 0)list.push_back(v[l]);
            }

            sort(ALL(list));
            ll rem = k - i - (n - 1 - j);
            if(rem < 0)continue;

            rep(r, rem){
                if(list[r] == INF)break;
                sum -= list[r];
            }
            res = max(res, sum);
        }
    }
    cout << res << endl;
}
