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

//https://betrue12.hateblo.jp/entry/2018/07/15/010448

//計算量はO(log max(a,b))
ll gcd(ll x,ll y){
  ll mindata,maxdata;
  mindata=min(x,y);
  maxdata=max(x,y);
  while(maxdata%mindata!=0){
    ll temp;
    temp=maxdata%mindata;
    maxdata=mindata;
    mindata=temp;
  }
  return mindata;
}


int main(){
    int T;
    cin>>T;
    while(T--){
        ll A,B,C,D;
        cin>>A>>B>>C>>D;
        if(A<B || D<B) cout<<"No"<<endl;
        else if(C>=B-1) cout<<"Yes"<<endl;
        else{
            ll g=gcd(B,D);
            A=A%B;
            ll t=C/g*g+A%g;
            if(t>C && t<B) cout<<"No"<<endl;
            else if(t+g<B) cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
    }
}
