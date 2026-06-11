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
    int n;
    cin>>n;
    map<string,double>mp;
    rep(i,n){
        double x;
        string s;
        cin>>x>>s;
        mp[s]+=x;
    }
    string s1="JPY",s2="BTC";
    double ans=mp[s1]+mp[s2]*380000;
    printf("%.4f\n",ans);

    return 0;
}