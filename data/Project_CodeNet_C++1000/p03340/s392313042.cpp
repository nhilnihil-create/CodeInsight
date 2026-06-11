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
    int n;
    cin >> n;
    VEC(ll, a, n);

    ll res = 0;
    int r = 0;
    ll rui_sum = 0,rui_xor = 0;
    for(int l = 0; l < n; l++){
        while(r < n && (rui_sum + a[r]) == (rui_xor ^ a[r])){
          //cout << rui_sum + a[r] << " " << (rui_xor ^ a[r]) << endl;
            rui_sum += a[r];
            rui_xor ^= a[r];
            r++;
        }
      //cout << l << " " << r << endl;
        res += r - l;
        if(r == l)r++;
        else {
            rui_sum -= a[l];
            rui_xor ^= a[l];
        }
    }

    cout << res << endl;
}