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

int main(){
    int N;
    cin>>N;
    ll A[210000];
    for(int i=1;i<=N;i++){
        cin>>A[i];
    }
    if(A[1]>0){
        cout<<-1<<endl;
        return 0;
    }
    ll ans=A[N],now=A[N]-1;
    for(int i=N-1;i>=1;i--,now--){
        if(A[i]==now) continue;
        if(now>A[i]){
            cout<<-1<<endl;
            return 0;
        }
        ans+=A[i];
        now=A[i];
    }
    cout<<ans<<endl;
}
