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

int main(){
    int n;cin>>n;
    string s;cin>>s;
    vector<ll> cnt(26,0);
    for(int i=0;i<n;i++){
        cnt[(int)(s[i]-'a')]++;
    }
    ll ans=1;
    for(int i=0;i<26;i++){
        if(cnt[i]>0) ans=ans*(cnt[i]+1)%MOD;
    }
    cout<<ans-1<<endl;
    return 0;
}