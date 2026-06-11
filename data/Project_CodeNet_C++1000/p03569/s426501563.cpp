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

//最大公約数
ll gcd(ll a, ll b){
    if(a % b == 0)return b;
    else return gcd(b, a % b);
}
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}
int main(){
   string s;
   cin >> s;
   vector<char> C;
   rep(i, s.size()){
       if(s[i] == 'x')continue;
       C.push_back(s[i]);
   }
   int l = 0, r = C.size() - 1;
   while(r - l >= 0){
       if(C[r] != C[l]){
           cout << -1 << endl;
           return 0;
       }
       r--;l++;
   }
   vector<int> cnt(C.size() + 1, 0);
   int now = 0;
   rep(i, s.size()){
       if(s[i] != 'x'){
           now++;
           continue;
       }
       cnt[now]++;
   }
   ll res = 0;
   l = 0, r = cnt.size() - 1;
   while(r - l >= 0){
       res += abs(cnt[r] - cnt[l]);
       r--;l++;
   }
   cout << res << endl;
}

