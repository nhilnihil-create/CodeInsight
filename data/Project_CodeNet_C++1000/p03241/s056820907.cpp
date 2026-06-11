//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/abc112/tasks/abc112_d

//参考：
//https://drken1215.hatenablog.com/entry/2018/11/06/120600

//ポイント：
//a1,a2,…,aN の最大公約数は必ず M の約数になる

//考え方
//(1)まず a1,a2,…,aN の最大公約数が必ず M の約数になることがわかる。
//(2)さらにd=GCD(a1,a2,…aN) とすると、ai≥d なので Nd ≤ M である
//よって
//答えは「M の約数 d のうち、Nd≤M を満たす最大のもの」

//(1)の説明
//dを a1,a2,…,aN の最大公約数とする
//この時 a1+a2+⋯+aN もdの倍数
//M = a1+a2+⋯+aN よりdはMの約数でもある

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

vector<LL> divisor(LL x){
	vector<LL> ret;
	for(int i=1;i*i<x;i++){
		if(x%i==0){
			ret.push_back(i);
			ret.push_back(x/i);
		}
	}
	sort(ret.begin(),ret.end());
	return ret;
}

LL N,M;

LL ans = 1;

void solve(){
	vector<LL> div = divisor(M);
	for(int i=0;i<div.size();i++){
		if(div[i]*N<=M) ans = div[i];
	}
}
 
int main(){
    cin >> N >> M;
 
    solve();

    cout << ans << endl;
    return 0;
}