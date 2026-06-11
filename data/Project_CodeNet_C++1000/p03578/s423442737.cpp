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
    vector<int> d(n);
    map<int,int> cnt;
    for(int i=0;i<n;i++){
        cin>>d[i];
        cnt[d[i]]++;
    }
    int m;cin>>m;
    int t;
    for(int i=0;i<m;i++){
        cin>>t;
        if(cnt[t]==0){
            cout<<"NO"<<endl;
            return 0;
        }else cnt[t]--;
    }
    cout<<"YES"<<endl;
    return 0;
}