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
    int a,b,k;
    cin>>a>>b>>k;
    int cnt=0;
    for(int i=100;i>0;--i){
        if(a%i==0&&b%i==0)k--;
        if(k==0)
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}