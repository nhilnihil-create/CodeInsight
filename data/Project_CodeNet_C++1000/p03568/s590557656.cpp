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
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int o=1,al=1;
    for(int i=0;i<n;i++){
        al*=3;
        if(a[i]%2==0) o*=2;
    }
    cout<<al-o<<endl;
    return 0;
}