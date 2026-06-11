#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,int> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=9999999999;
ll c[10][10];
ll dp[10];


int main(){
    int h,w;
    cin>>h>>w;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>c[i][j];
        }
    }
    priority_queue<P,vector<P>,greater<P> > q;
    for(int i=0;i<10;i++) dp[i]=INF;
    q.push(P(0,1));
    dp[1]=0;
    while(!q.empty()){
        P p=q.top(); q.pop();
        int now=p.second;
        ll cost=p.first;
        for(int from=0;from<10;from++){
            if(from==now) continue;
            if(dp[from]>cost+c[from][now]){
                dp[from]=cost+c[from][now];
                q.push(P(dp[from],from));
            }
        }
    }
    ll ans=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int a;
            cin>>a;
            if(a==-1) continue;
            ans+=dp[a];
        }
    }
    cout<<ans<<endl;


}