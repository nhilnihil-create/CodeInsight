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
    ll n;
    cin >> n;

    for(ll i = 1; i <= 3500; i++){
        for(ll j = 1; j <= 3500; j++){
            if(4 * i * j - (i + j) * n <= 0)continue;

            if(n * i * j % (4 * i * j - (i + j) * n) == 0){
              	ll k = n * i * j / (4 * i * j - (i + j) * n);
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }
}

