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


using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;




int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> v(n + 1);
    int now, cnt = 0;
    rep(i, s.size()){
        if(s[i] == 'A')now = 0;
        else if(s.substr(i, 2) == "BC"){now = 1;i++;}
        else {
            v[cnt].push_back(INF);
            cnt++;
            continue;
        }
        v[cnt].push_back(now);
    }
    v[cnt].push_back(INF);

    ll res = 0;
    rep(i, n){
        int lim = lower_bound(ALL(v[i]), INF) - v[i].begin() - 1;
        rep(j, v[i].size()){
            if(v[i][j] == INF)break;
            if(v[i][j] == 0){
                //if(lim < j)break;
                res += lim - j;
                lim--;
            }
        }
    }
    cout << res << endl;
}
