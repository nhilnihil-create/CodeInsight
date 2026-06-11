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
using P = pair<char,int>;

const ll MOD = INF + 7;

int main(){
   int n;
   cin >> n;
   vector<int> t(n), x(n), y(n);
   rep(i, n){
       cin >> t[i] >> x[i] >> y[i];
       if(t[i] < x[i] + y[i]){
           cout << "No";
           return 0;
       }
   }

   REP(i, 1, n - 1){
       if(t[i] - t[i - 1] < abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1])){
           cout << "No";
           return 0;
       }
   }
   REP(i, 0, n - 1){
       if(t[i] % 2 != (x[i] + y[i]) % 2){
           cout << "No";
           return 0;
       }
   }
   cout << "Yes";
}

