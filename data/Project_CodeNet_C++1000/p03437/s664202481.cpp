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
    ll x,y;cin>>x>>y;
  if(x%y==0){
    cout<<-1<<endl;
    return 0;
  }
    for(ll i=1;true;i++){
        if(x<=1000000000000000000/i){
            if((x*i)%y!=0){
                cout<<x*i<<endl;
                return 0;
            }else continue;
        }else{
            cout<<-1<<endl;
            return 0;
        }
    }
}