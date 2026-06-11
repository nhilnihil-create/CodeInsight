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
using P = pair<int,int>;

vector<int>bitSearch(int bit,int n){
    vector<int>S;
    rep(i,n)if(bit&(1<<i))S.push_back(i);
    return S;
}


int main(){
    int n, z, w;
    cin >> n >> z >> w;
    vector<ll> X(n + 1), Y(n + 1), a(n);
    rep(i, n){
        cin >> a[n - i - 1];
    }

    X[0] = abs(w - a[0]);
    X[1] = abs(a[1] - a[0]);
    Y[1] = X[1];

    REP(i, 2, n - 1){
        X[i] = abs(a[i] - a[0]);
        REP(j, 1, i - 1){
            X[i] = min(X[i], Y[j]);
        }

        Y[i] = abs(a[i] - a[0]);
        REP(j, 1, i - 1){
            Y[i] = max(Y[i], X[j]);
        }
    }
    ll res = 0;
    rep(i, n){
        res = max(res, X[i]);
    }
    cout << res << endl;
}

