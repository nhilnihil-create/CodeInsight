#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(v) v.begin(), v.end()
//
int main(){
   int N,M;
   vector<string> blue,red;
   map<string,int> p;
   cin>>N;
   rep(i,N){
      string s;
      cin>>s;
      blue.push_back(s);
   }
   cin>>M;
   rep(i,M){
      string s;
      cin>>s;
      red.push_back(s);
   }
   rep(i,N){
      p[blue[i]]++;
   }
   rep(i,M){
      p[red[i]]--;
   }
   int ans=0;
   for(auto e:blue){
      ans=max(ans,p[e]);
   }
   cout<<ans<<endl;
}

