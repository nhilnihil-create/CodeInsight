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
#define MAX 110000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;
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
    string s0;
    cin>>N;
    cout<<0<<endl;
    cin>>s0;
    if(s0=="Vacant") return 0;
    int ng=0,ok=N,count=0;
    while(true){
        count++;
        if(count>20) return 1;
        int mid=(ng+ok)/2;
        cout<<mid<<endl;
        string s; cin>>s;
        if(s=="Vacant") return 0;
        if((mid%2==0 && s==s0) || (mid%2==1 && s!=s0)){
            ng=mid;
        }else ok=mid;
    }
}
