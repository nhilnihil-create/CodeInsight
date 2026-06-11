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
#include<cassert>
#include<cmath>
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

const ll MOD = INF + 7;



int main(){
    int n;
    string s;
    cin >> n >> s;

    vector<int> cnt_w(n + 1), cnt_b(n + 1);
    rep(i, n){
        if(s[i] == '#')cnt_b[i + 1]++;
        if(s[i] == '.')cnt_w[i + 1]++;
        cnt_b[i + 1] += cnt_b[i];
        cnt_w[i + 1] += cnt_w[i];
    }
    int res = INF;
    rep(i, n + 1){
        res = min(res, cnt_b[i] + cnt_w[n] - cnt_w[i]);
    }
    cout << res << endl;
}