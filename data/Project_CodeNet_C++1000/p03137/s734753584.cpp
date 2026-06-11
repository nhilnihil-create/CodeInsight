#include<cmath>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<functional>
#define INF 1e16
#define N (1000000000+7)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> Q;


ll gcd(ll a, ll b) {
    if(b==0) return abs(a);
	else return gcd(b, a%b);
}


int main(void){
    int n,m;
    cin>>n>>m;
    vector<ll>x(m);
    for(int i=0;i<m;i++)cin>>x[i];
    if(m<=n){
        cout<<0<<endl;
        return 0;
    }
    if(m==1){
        cout<<0<<endl;
        return 0;
    }
    sort(x.begin(),x.end());
    vector<ll>d;
    ll sum = 0;
    for(int i=0;i<m-1;i++){
        d.push_back(x[i+1]-x[i]);
        sum+=x[i+1]-x[i];
    }
    sort(d.begin(),d.end(),greater<ll>());
    for(int i=0;i<n-1;i++)sum-=d[i];
    cout<<sum<<endl;
    return 0;
}