#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
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

int main(){
    int n;cin>>n;
    int a,b;cin>>a>>b;
    int p[n];
    for(int i=0;i<n;i++) cin>>p[i];
    int c1=0,c2=0,c3=0;
    for(int i=0;i<n;i++){
        if(p[i]<=a) c1++;
        else if(a<p[i]&&p[i]<=b) c2++;
        else c3++;
    }
    cout<<min(min(c1,c2),c3)<<endl;
    return 0;
}