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
   vector<ll> a(n), b(n);
   ll suma = 0, sumb = 0;
   rep(i, n){
      cin >> a[i];
      suma += a[i];
   }
   bool f = true;
   rep(i, n){
      cin >> b[i];
      if(a[i] != b[i])f = false;
      sumb += b[i];
   }
   ll man = sumb - suma;
   if(man < 0){
      cout << "No" << endl;
      return 0;
   }
   else if(man == 0){
      cout << (f ? "Yes" : "No") << endl;
      return 0;
   }
   else {

      ll cnta = man, cntb = man;
      rep(i, n){
         ll diff = b[i] - a[i];
         if(diff > 0){
            cnta -= (diff + 1) / 2;
            a[i] += (((diff + 1) / 2) * 2);
            if(cnta <= 0)break;
         }
      }
      rep(i, n){
         ll diff = a[i] - b[i];
         if(diff > 0){
            cntb -= diff;
            b[i] += diff;
            if(cntb <= 0)break;
         }
      }

      bool g = true;
     if(cnta < 0 || cntb < 0)g = false;
      rep(i, n){
         if(a[i] != b[i])g = false;
      }
      if(g && cntb == 2 * cnta){
         cout << "Yes" << endl;
      }
      else cout << "No" << endl;
   }
}