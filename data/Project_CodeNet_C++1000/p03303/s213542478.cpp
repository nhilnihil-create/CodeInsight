/*
このコード、と～おれ!
Be accepted!
∧＿∧　
（｡･ω･｡)つ━☆・*。
⊂　　 ノ 　　　・゜+.
　しーＪ　　　°。+ *´¨)
 　　　　　　　　　.· ´¸.·*´¨) ¸.·*¨)
		  　　　　　　　　　　(¸.·´ (¸.·'* ☆
					*/

#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <vector>
#include <numeric>
#include <iostream>
#include <random>
#include <map>
#include <unordered_map>
#include <queue>

#pragma GCC optimize("Ofast")
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
#define rep2(i, n) for(int i = 2; i < (n); ++i)
#define repr(i, n) for(int i = n; i >= 0; --i)
#define reprm(i, n) for(int i = n - 1; i >= 0; --i)
#define printynl(a) printf(a ? "yes\n" : "no\n")
#define printyn(a) printf(a ? "Yes\n" : "No\n")
#define printYN(a) printf(a ? "YES\n" : "NO\n")
#define printin(a) printf(a ? "possible\n" : "inposible\n")
#define printdb(a) printf("%.16f\n", a)//少数出力
#define prints(s) printf("%s\n", s.c_str())//string出力
#define all(x) (x).begin(), (x).end()
#define allsum(a, b, c) ((a + b) * c / 2)//等差数列の和、初項,末項,項数
#define pb push_back
#define priq priority_queue

using ll = long long;

const int INF = 1073741823;
const int MINF = -1073741823;
const ll LINF = ll(4661686018427387903);
const ll MOD = 1000000007;
const double PI = acos(-1);

using namespace std;

void scans(string & str) {
	char c;
	scanf("%c", &c);
	while (c != '\n' && c != -1) {
		str += c;
		scanf("%c", &c);
	}
}

/*-----------------------------------------ここからコード-----------------------------------------*/


int main() {

	string s;
	int w;
	scans(s);
	scanf("%d", &w);
	for (int i = 0; i < s.length(); i += w) {
		printf("%c", s[i]);
	}
	printf("\n");

 	return 0;
}
