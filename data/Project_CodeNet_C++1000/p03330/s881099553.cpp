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
    vector<int>S,False(1,-1);
    rep(i,n)if(bit&(1<<i))S.push_back(i);
    return S;
}

template<typename A,size_t N,typename T>
void Fill(A(&array)[N],const T &val){
    fill((T*)array,(T*)(array+N),val);
}

void warshall_floyd(int n, vector<vector<int>>&d){
    rep(k, n){
        rep(i, n){
            rep(j, n){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}


const ll INF = 1e12;
int main(){
    int n, c;
    cin >> n >> c;
    vector<vector<int>>cost(c, vector<int>(c));        //色変化にかかるコストの隣接行列
    vector<vector<int>>field(n, vector<int>(n));    //グリッドの色
    
    rep(i, c)rep(j, c)cin >> cost[i][j];
    rep(i, n)rep(j, n)cin >> field[i][j];

    //warshall_floyd(c, cost);

    map<int, int>remainder_0;
    map<int, int>remainder_1;
    map<int, int>remainder_2;

    rep(i, n){
        rep(j, n){
            if((i+j) % 3 == 0)remainder_0[ field[i][j] - 1 ]++;
            if((i+j) % 3 == 1)remainder_1[ field[i][j] - 1 ]++;
            if((i+j) % 3 == 2)remainder_2[ field[i][j] - 1 ]++;
        }
    }

    ll res = INF;
    for(int i = 0; i < c; i++){
        for(int j = 0; j < c; j++){
            for(int k = 0; k < c; k++){
                if(i == j || j == k || k == i)continue;
                ll sum = 0;
                for(auto r : remainder_0){
                    sum += cost[r.first][i] * r.second;
                }
                for(auto r : remainder_1){
                    sum += cost[r.first][j] * r.second;
                }
                for(auto r : remainder_2){
                    sum += cost[r.first][k] * r.second;
                }

                res = min(res, sum);
            }
        }
    }

    cout << res << endl;
}