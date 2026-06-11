#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<utility>
#include<cstdio>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std;
#define rep(i,x,n) for(int i=x;i<n;i++)
typedef long long ll;
typedef pair<int,int> P;
string s;
int k;
int INF=1000000000;
int dh[4]={0,1,0,-1};
int dw[4]={1,0,-1,0};

int main(){
    ll x,y;
  cin>>x>>y;
    ll ans=0;
    ll t=x;
    while(t<=y){
        t*=2;
        ans++;
    }
    cout<<ans<<endl;
}