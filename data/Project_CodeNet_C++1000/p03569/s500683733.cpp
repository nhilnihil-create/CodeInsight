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
using P = pair<char,int>;


int main(){
   string s;
   cin >> s;
   deque<P> deq;

   const int len = s.size();
   bool all_x = true;
   rep(i, len){
       if(s[i] == 'x')continue;
       if(s[i] != 'x')all_x = false;
       deq.push_back(P(s[i], i));
   }

   if(all_x){
       cout << 0;
       return 0;
   }

   bool f = true;
   int l, r;
   while(!deq.empty()){
       if(deq.front().first != deq.back().first)f = false;
       l = deq.front().second;
       r = deq.back().second;

       deq.pop_front();
       if(deq.empty())break;
       deq.pop_back();
   }

   if(!f){
       cout << -1 << endl;
       return 0;
   }
   else {
       int res = 0;
       while(l >= 0 || r <= len - 1){
           if(l < 0 || r > len - 1){
               res++;
               l--;
               r++;
               continue;
           }
           
           if(s[l] == s[r]){
               l--;
               r++;
           }
           else if(s[l] != s[r] && s[l] == 'x'){
               res++;
               l--;
           }
           else if(s[l] != s[r] && s[r] == 'x'){
               res++;
               r++;
           }
       }
       cout << res << endl;
       return 0;
   }
}

