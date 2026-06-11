#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;
ll MOD = 1e9+7;
//LLONG_MIN

/*
高速ゼータ変換を使う（２次元配列を使った遷移を１次元配列に落とし込む）
このスライドがとても分かりやすい．
https://www.ioi-jp.org/joi/2017/2018-ho/2018-ho-t5-review.pdf
*/

mp f(mp a,mp b){//大きい順に２つとるだけ
	ll c[4]={a.first,a.second,b.first,b.second};
	sort(c,c+4);
	return make_pair(c[3],c[2]);
}

int main(void){
	ll n,c[1<<18];
	mp b[1<<18];
	cin>>n;
	rep(i,1<<n){
		ll a;
		cin>>a;
		b[i]=make_pair(a,0);
	}
	//高速ゼータ変換
	rep(i,n){//注目bit
		rep(m,1 << n){
			if(0 == (m & (1<<i))){//mのibitが0なら遷移
				b[m|(1<<i)] = f(b[m|(1<<i)],b[m]);//ないやつをあるやつに送る
			}
		}
	}
	rep(i,1<<n)c[i]=b[i].first+b[i].second;
	rep(i,(1<<n)-1)c[i+1]=max(c[i],c[i+1]);
	reg(i,1,(1<<n)-1)cout<<c[i]<<endl;
	return 0;
}