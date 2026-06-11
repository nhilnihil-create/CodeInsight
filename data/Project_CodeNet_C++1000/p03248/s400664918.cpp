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
typedef pair<int,int> P;
//typedef pair< pair<int,int>,pair<int,int> > p;
//#define int ll int main->signed main
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
struct edge{ll to,cost,val;};
template<class T,class U>bool chmin(T&a,const U&b){if(a<=b)return false;a=b;return true;}
template<class T,class U>bool chmax(T&a,const U&b){if(a>=b)return false;a=b;return true;}
//__builtin_popcount(S);
//C.erase(unique(C.begin(),C.end()),C.end());

//http://drken1215.hatenablog.com/entry/2018/09/30/004816

int main(){
    string S;
    cin>>S;
    if(S[0]=='0' || S.back()=='1'){
        cout<<-1<<endl;
        return 0;
    }
    int N=(int)S.size();
    bool ok=true;
    for(int i=1;i<N;i++){
        int j=N-i;
        if(S[i-1]!=S[j-1]) ok=false;
    }
    if(!ok){
        cout<<-1<<endl;
        return 0;
    }
    int pre=N;
    for(int i=N-1;i>=1;i--){
        cout<<i<<" "<<pre<<endl;
        if(S[i-1]=='1') pre=i;
    }
}
