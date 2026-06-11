/*
貪欲
後ろから見る
DP
順位表をチェック
二分探索
不変なもの・偶奇に注目

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
#define INF 1LL<<60
#define MAX 100000
#define MOD 1000000007
typedef long long ll;
//typedef pair<ll,int> P;
//typedef pair< pair<int,int>,pair<int,int> > p;
//#define int ll int main->signed main
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
struct edge{ll to,cost,val;};
template<class T,class U>bool chmin(T&a,const U&b){if(a<=b)return false;a=b;return true;}
template<class T,class U>bool chmax(T&a,const U&b){if(a>=b)return false;a=b;return true;}
//__builtin_popcount(S);
//C.erase(unique(C.begin(),C.end()),C.end());

//http://kmjp.hatenablog.jp/entry/2018/11/26/0900

ll C[2100000],M[2100000],CM[2100000];

int main(){
    int N; string S; int Q;
    cin>>N>>S>>Q;
    for(int i=0;i<N;i++){
        M[i+1]+=M[i]+(S[i]=='M');
        C[i+1]+=C[i]+(S[i]=='C');
        CM[i+1]=CM[i];
        if(S[i]=='C'){
            CM[i+1]+=M[i];
        }
    }
    for(int i=N+1;i<=2000000;i++){
        C[i]=C[i-1];
        M[i]=M[i-1];
        CM[i]=CM[i-1];
    }
    while(Q--){
        int K;
        cin>>K;
        ll ret=0;
        for(int i=0;i<N;i++){
            if(S[i]=='D'){
                ll cm=CM[i+K]-CM[i];
                ll mi=M[i]*(C[i+K]-C[i]);
                //cout<<C[i+]<<endl;
                ret+=cm-mi;
                //cout<<ret<<endl;
            }
        }
        cout<<ret<<endl;
    }

}
