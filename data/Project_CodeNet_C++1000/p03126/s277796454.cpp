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
     int n,m;
     cin>>n>>m;
     vector<int>v(m);
     rep(i,n){
         int k;
         cin>>k;
         rep(i,k){
             int a;
             cin>>a;
             a--;
             v[a]++;
         }
     }
     int ans=0;
     rep(i,m){
         if(v[i]==n)ans++;
     }
     cout<<ans<<endl;
}