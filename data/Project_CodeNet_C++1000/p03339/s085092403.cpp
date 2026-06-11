#include <bits/stdc++.h>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <set>
#include <cmath>
#include <tuple>
#include <vector>
#include <array>
typedef long long ll;

//マクロ
//forループ関係
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//xにはvectorなどのコンテナ
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
#define D()
//定数
#define INF 1000000000000 //10^12:極めて大きい値,∞
#define MOD 1000000007 //10^9+7:合同式の法
#define MAXR 100000 //10^5:配列の最大のrange(素数列挙などで使用)
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素

int main(){
	int n;
	std::string s;
	std::cin >> n;
	std::cin >> s;
	int l[3*100000+10];
	int r[3*100000+10];
	int a[3*100000+10];
	int lnum=0,rnum=0;
	for ( int i = 0 ; i < n ; i++ ) {
		if(s[i]=='W'){
			lnum ++;
		}
		if(s[n-1-i]=='E'){
			rnum ++;
		}
		l[i] = lnum;
		r[n-1-i] = rnum;
	}
	for ( int i = 0 ; i < n ; i++ ) {
		a[i] = l[i] + r[i];
		// std::cout << i<< " : "<<a[i] << " l:"<<l[i] << " r:"<<r[i] << std::endl;
	}
	ll min = INF;
	int index = 0;
	for ( int i = 0 ; i < n ; i++ ) {
		if (min > a[i]){
			min = a[i];
		}
	}
	std::cout << min-1 << std::endl;

	return 0;
}
