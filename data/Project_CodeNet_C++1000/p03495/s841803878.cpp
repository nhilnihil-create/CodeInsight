#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
   int n,k;
   string s;
   cin >> n >> k;
   map<int,int> m;
   int kind = 0;
   vector<int> v;
   rep(i,n){
      int tmp;
      cin >> tmp;
      if (!m.count(tmp)) kind++;
      m[tmp]++; 
   }
   int ans = 0;
   for (auto w:m){
      v.push_back(w.second);
   }
   sort(v.begin(),v.end());
   if (kind-k == 0) ans = 0;
   else {
      rep(i,kind-k){
         ans+=v[i];
      }
   }
   cout << ans << endl;

   return 0;
}
