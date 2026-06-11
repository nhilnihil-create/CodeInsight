#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P=pair<int,int>;

int main(){
   int n,m,X,Y; cin>>n>>m>>X>>Y;
   vector<int> x(n);
   vector<int> y(m);
   rep(i,n) cin>>x[i];
   rep(i,m) cin>>y[i];
   sort(x.begin(),x.end());
   sort(y.begin(),y.end());
   int maxx=x[n-1]+1;
   int miny=y[0];
   if(maxx<=miny){
      if(X<maxx && miny<=Y){
         cout<<"No War"<<endl;
      }
      else cout<<"War"<<endl;
   }
   else cout<<"War"<<endl;
   return 0;
}