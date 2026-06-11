#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
   int n;
   cin >> n;
   vector<ll> a(n);
   rep(i,n)cin >> a.at(i);
   unordered_map<int ,int> cnt;
   rep(i,n){
      if(cnt.count(a[i])){
         cnt.at(a[i])++;
      }
      else{
         cnt[a[i]]=1;
      }
   }
   ll sum=0;
   for(auto p:cnt){
      auto k=p.first;
      auto v=p.second;
      if(v>=k){
         sum+=v-k;
      }
      else{
         sum+=v;
      }
   }
   cout << sum << endl;
}