#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7 
#define LINF 1e15+7 
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;


int main(){
    
    int x,y,z,k;
    cin>>x>>y>>z>>k;
    vector<ll>a(x),b(y),c(z);
    rep(i,x)cin>>a[i];
    rep(i,y)cin>>b[i];
    rep(i,z)cin>>c[i];
    
    vector<ll>ab;
    rep(i,x)rep(j,y){
        ab.push_back(a[i]+b[j]);
    }
    vector<ll>abc;
    sort(ab.rbegin(),ab.rend());
    rep(i,min(k,x*y))rep(j,z){
        abc.push_back(ab[i]+c[j]);
    }
    sort(abc.rbegin(),abc.rend());
    rep(i,k){
        cout<<abc[i]<<endl;
    }
    
    return 0;
}