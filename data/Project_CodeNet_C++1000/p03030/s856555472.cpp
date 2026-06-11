#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
 
 int main() {
    int N;cin>>N;
	vector<tuple<string,int,int>> vec;
    rep(i,N){
      string st="";cin>>st;
      int a=0;cin>>a;
      tuple<string,int,int> tup(st,(-1)*a,i+1);
      vec.push_back(tup);
    }
   
   sort(vec.begin(),vec.end());
   
   rep(i,N){
     int ans;
     tie(ignore,ignore,ans)=(vec[i]);
     cout << ans << endl;
   }
 }