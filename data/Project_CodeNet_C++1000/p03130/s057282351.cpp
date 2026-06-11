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
    int a,b;
    vector<int> c(4,0);
    for(int i=0;i<3;i++){
        cin>>a>>b;
        a--;b--;
        c[a]++;c[b]++;
    }
    for(int i=0;i<4;i++){
        if(c[i]==3){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}