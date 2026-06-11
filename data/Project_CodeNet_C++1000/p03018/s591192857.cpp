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
   string s;
   cin >> s;
   vector<vector<int>> list(2000000);
   int now = 0;
   rep(i, s.size() - 1){
       if(s[i] == 'A'){
           list[now].push_back(0);
       }
       else if(s.substr(i, 2) == "BC"){
           list[now].push_back(1);
           i++;
       }
       else {
           now++;
       }
   }
   list[now].push_back(INF);
   
   ll res = 0;
   rep(i, now+1){
       ll end = list[i].size() - 1;
       if(list[i][list[i].size()-1] == INF)end--;
       rep(j, list[i].size()){
           if(list[i][j] == INF){
               cout << res << endl;
               return 0;
           }
           if(list[i][j] == 0){
               res += (end - j);
               end--;
           }
       }
   }
}

