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
    string s;
    cin>>s;
    int y=0,m=0,d=0;
    rep(i,4)y=y*10+(s[i]-'0');
    rep(i,2)m=m*10+(s[i+5]-'0');
    rep(i,2)d=d*10+(s[i+8]-'0');
    bool ok=true;
    if(y>2019)ok=false;
    if(y==2019&&m>4)ok=false;
    if(y==2019&&m==4&&d>30)ok=false;
    if(ok)cout<<"Heisei"<<endl;
    else cout<<"TBD"<<endl;
    return 0;
}