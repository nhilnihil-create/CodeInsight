#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

int main(){
   int n,m;
   cin >> n >> m;
   vector<vector<int>> v(n);
   vector<pair<int,int>> per(m);
   rep(i,m){
      int x,y;
      cin >> x >> y;
      x--;
      v[x].push_back(y);
      per[i] = {x+1,y};
   }
   rep(i,n){
      if (v[i].size() == 0) continue;
      sort(v[i].begin(),v[i].end());
   }
   rep(i,m){
      int x,y; 
      x = per[i].first; y = per[i].second;
      printf("%06d",x);
      printf("%06d\n",int(lower_bound(v[x-1].begin(),v[x-1].end(),y)-v[x-1].begin())+1);
   }
   //printf("%06d",100000);
   
   
   return 0;
   
}

