#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;


int main(){
   int n,k;
   cin>>n>>k;
   vector<int>h(n);
   rep(i,n)cin>>h[i];
   sort(h.begin(),h.end());
   int ans=INF;
   for(int i=0;i+k<=n;i++){
       ans=min(abs(h[k+i-1]-h[i]),ans);
   }
    cout<<ans<<endl;
    return 0;
}