/*
貪欲
後ろから見る
DP
順位表をチェック
二分探索


*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include <map>
#include<tuple>
#include<set>
using namespace std;
#define INF 1100000000000000000
#define MAX 100000
#define MOD 1000000007
typedef long long ll;
//typedef pair<int,int> P;
//typedef pair< pair<int,int>,pair<int,int> > p;
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
struct edge{ll to,cost,val;};
template<class T,class U>bool chmin(T&a,const U&b){if(a<=b)return false;a=b;return true;}
template<class T,class U>bool chmax(T&a,const U&b){if(a>=b)return false;a=b;return true;}
//__builtin_popcount(S);
//C.erase(unique(C.begin(),C.end()),C.end());

ll h[40];

int main(){
    int N;
    cin>>N;
    map<ll,int> M;
    priority_queue<ll> que;
    for(int i=0;i<N;i++){
        ll a;
        cin>>a;
        que.push(a);
        M[a]++;
    }
    h[0]=1;
    for(int i=1;i<=35;i++){
        h[i]=h[i-1]*2;
    }
    int ans=0;
    for(int i=0;i<N;i++){
        ll t=que.top(); que.pop();
        if(M[t]==0) continue;
        M[t]--;
        for(int i=0;i<=35;i++){
            if(M.find(h[i]-t)!=M.end() && M[h[i]-t]>0){
                M[h[i]-t]--;
                ans++;
                break;
            }
        }
    }
    cout<<ans<<endl;

}
