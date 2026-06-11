#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<tuple>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int INF=1e9;
const ll MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int dis2(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
ll power(ll a,ll x){
    ll res=1;
    while(x>0){
        if(x&1) res=res*a%MOD;
        a=a*a%MOD;
        x>>=1;
    }
    return res;
}
string s;
int g(int i){
    if(i<0) return 0;
    if(i==0) return 1;
    if(i==1&&s[1]==s[0]) return 1;

}
int main(){
    ll n,m,d;
    cin>>n>>m>>d;
    if(d==0){
        printf("%.10f\n",(double)(m-1)/(double)n);
    }else{
        printf("%.10f\n",(double)(2*(n-d)*(m-1))/(double)(n*n));
    }
    cout<<endl;
    return 0;
}