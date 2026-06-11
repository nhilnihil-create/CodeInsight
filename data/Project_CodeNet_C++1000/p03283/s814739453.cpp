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
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)


using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

int main(){
    int n, m, Q;
    cin >> n >> m >> Q;
    vector<vector<ll>> LR(n + 1);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        LR[a].push_back(b);
    }
    rep(i, n + 1){
        sort(ALL(LR[i]));
        LR[i].push_back(INF);
    }

    rep(i, Q){
        int p, q;
        cin >> p >> q;
        ll sum = 0;
        REP(j, p, q){
            sum += (upper_bound(ALL(LR[j]), q) - LR[j].begin());
            //if(*lower_bound(ALL(LR[j]), q) == q)sum++;
        }
        cout << sum << endl;
    }
    
}