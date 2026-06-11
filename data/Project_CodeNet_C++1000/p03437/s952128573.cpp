#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<float.h>
#include<tuple>
#include<string.h>
#include<iomanip>
#include<stack>
#include<queue>
#include<map>
#include<deque>

using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define ALLOF(c) (c).begin(), (c).end()
#define Pa pair<ll,ll>
const ll mod=1000000007;
const ll INF=10e12;
const ll inf=-1;
ll ABS(ll a){return max(a,-a);}


int main(void){
    ll X,Y;
    cin>>X>>Y;
    if(X%Y==0) cout<<-1<<endl;
    else cout<<X<<endl;
    return 0;
}