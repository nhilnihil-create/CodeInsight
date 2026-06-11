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
    ll sum=0,x=1100000000;
    bool flag=true;
    for(int i=0;i<N;i++){
        ll A,B;
        cin>>A>>B;
        if(A!=B) flag=false;
        if(A>B) x=min(x,B);
        sum+=A;
    }
    if(flag) cout<<0<<endl;
    else{
        cout<<sum-x<<endl;
    }

}
