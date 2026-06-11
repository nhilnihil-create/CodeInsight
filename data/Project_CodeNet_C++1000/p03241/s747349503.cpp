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
    int ans=0;
    vector<int>a;
    for(int i=n;i*i<=m;i++){
        if(m%i==0){
            ans=m/i;
            break;
        }
    }
    if(ans==0){
        for(int i=n-1;i>=1;i--){
            if(m%i==0&&m/i>=n){
                ans=i;
                break;
            }
        }
    }
    
    cout<<ans<<endl;
    return 0;
}