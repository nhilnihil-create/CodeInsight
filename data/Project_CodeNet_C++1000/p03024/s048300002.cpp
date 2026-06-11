#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int INF=1e9;
const ll MOD=1e9+7;

ll gcd(ll x,ll y){
    if(y==0) return 0;
    return gcd(y,x%y);
}

int dis2(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

double cut(int r,int n,int i){
    double res=r*r-(r-r*(double)i/(double)n)*(r-r*(double)i/(double)n);
    return pow(res,0.5)*2;
}

int main(){
    string s;cin>>s;
    int k=(int)s.size();
    int o=0;
    for(int i=0;i<k;i++)if(s[i]=='o') o++;
    if(o+(15-k)>=8) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}