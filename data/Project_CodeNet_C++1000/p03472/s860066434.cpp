#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional> //operator[]
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define Rep(i,n) for(int i=1;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define Rrep(i,n) for(int i=n-1;i>0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
#define P pair<int,int>
#define Pll pair<ll,ll>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main(){
    int n,h; cin >> n >> h;
    priority_queue<P> pq;
    rep(i,n){
        int x,y; cin >> x >> y;
        pq.push({x,0});
        pq.push({y,1});
    }
    int ans=0;
    while(!pq.empty()&&h>0){
        P p=pq.top(); pq.pop();
        if(p.se==1){
            h-=p.fi; ans++;
        }else{
            ans+=(h+p.fi-1)/p.fi;
            break;
        }
    }
    cout << ans << endl;
}
