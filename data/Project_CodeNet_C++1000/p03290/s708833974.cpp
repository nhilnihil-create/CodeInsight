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

//bit全探索
vector<ll>bitSearch(int bit,int n){
    vector<ll>S;
    rep(i,n)if(bit&(1<<i))S.push_back(i);
    S.push_back(1e9);
    return S;
}

int main(){
    int d, g;
    cin >> d >> g;
    vector<int> p(d), c(d), total(d);
    rep(i, d){
        cin >> p[i] >> c[i];
        total[i] = 100 * (i + 1) * p[i] + c[i];
    }
    
    ll res = INF;
    for(int bit = 0; bit < (1 << d); bit++){
        vector<ll> S = bitSearch(bit, d);
        ll sum = 0, cnt = 0;
        for(ll s : S){
            if(s == INF)break;
            sum += total[s];
            cnt += p[s];
        }
        ll rem = g - sum;
        if(g <= sum){
            res = min(res, cnt);
        }
        else {
            for(int i = d - 1; i >= 0; i--){
                if(i == *lower_bound(ALL(S), i))continue;
                
                REP(j, 1, p[i] - 1){
                    if(sum >= g)break;
                    sum += 100 * (i + 1);
                    cnt++;
                }
                if(sum >= g)break;
            }
            if(g <= sum)res = min(res, cnt);
        }
    }
    cout << res << endl;
}
