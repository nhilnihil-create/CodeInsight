//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/agc022/tasks/agc022_b

//参考：
//https://competitive12.blogspot.com/2019/09/agc-022-b-gcd-sequence.html

//ポイント1：
//最初に条件を満たす、ベースとなる小さい数列を作り、そこから特別性を壊さないよう値を加えていく

//ポイント2：
//mod2と3を見る
//例えば{2,4,3,9}は
//mod2では{0,0,1,1}
//mod3では{2,1,0,0}

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
#include <stack>
#include <map> 
#include <unordered_map> 
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

LL N;

LL ans[20000];

void solve(){
	if(N==3){
		ans[0] = 2;ans[1] = 5;ans[2] = 63;
		return;
	}
	ans[0] = 2;
	ans[1] = 4;
	ans[2] = 3;
	ans[3] = 9;
	int counter = 0;
	LL two = 6;
	LL three = 12;
	LL six = 6;

	auto add_six= [&](int length){
		ans[length] = six;
		six+=6;
	};
	auto add_two= [&](int length){
		if(two<=30000){
			if(two%3==0) two+=2;
			ans[length] = two;
			two+=2;
			if(two%3==0) two+=2;
			if(two<=30000){
				ans[length+1] = two;
				two+=2;
			}
			else{
				add_six(length);
				add_six(length+1);
			}
		}else{
			add_six(length);
			add_six(length+1);
		}
	};
	auto add_three= [&](int length){
		if(three<=30000){
			if(three%2==0) three+=3;
			ans[length] = three;
			three+=3;
			if(three%2==0) three+=3;
			if(three<=30000){
				ans[length+1] = three;
				three+=3;
			}
			else{
				add_six(length);
				add_six(length+1);
			}
		}else{
			add_six(length);
			add_six(length+1);
		}
	};
	if(N%2==0){
		for(int length = 4;length<N;length+=2){
			if(counter%2==0){
				add_two(length);
			}else{
				add_three(length);
			}
			counter++;
		}
	}else{
		N--;
		for(int length = 4;length<N;length+=2){
			if(counter%2==0){
				add_two(length);
			}else{
				add_three(length);
			}
			counter++;
		}
		N++;
		add_six(N-1);
	}
}

int main(){
    cin >> N;

    solve();

    for(int i=0;i<N;i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}