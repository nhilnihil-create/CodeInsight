/*　　　　　　　{:i:i:|:i:i:/l/--　 　 　 --l/li:i:i|i:i:i:i}
　　　　　　 　 {:rx|:i:iィi芥ミ 　 　 .ィi芥ミｉ:ｉ:|ﾍ:i:i:}
.　　　 　 　 　 ｛ﾏ|ｉ: {::’:} 　 　 　 {:‘::} :ｉ:i:|〉｝:/
　　 　 　 　 　 乂|:i:| ｀¨¨´ 　 　　　 ｀¨¨´:i:ｉ:|ｼ/
　 　 　 　 　 　 ﾉ:|:i|　　　　　　′　　　 　   |:i:i:|ﾂ
　　　　　　　　/:/|:i:| ､　　　 　_ _ 　　　　  |:i:i:|
　 　 　　 　 /:/ .|:i:|/ ＼　　　 　 　     ｨ〔|:i:/
　　 　 　  　 〈;/ く刈＿ 个 　   -   　＜}　./|/_〉
　　     　　 r-っ'~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ|___
　　 　     /／ニつ　　　　　　 ､　　　　　　　ノﾆﾆ　＼
.　　　     |　　ニ⊃ 　./　/　 ──   /　/　　..⊆ﾆﾆ　　:|
.　　　     |　　丁´　 /|￣|￣  ─‐ /|￣|￣ 　 .￣|丁 　|
.　　　     |　　ﾉ.  　 |￣|￣  ─‐  |￣|￣ 　 　.|八 　|
.　　　     |　　||. 　 |￣|￣ |￣| |￣|￣ 　   .|　|
.　 　 　   |  　||   　￣￣￣　￣ 　￣￣￣　　  .|　|  |
.　 　 　  　    ||＿＿＿＿＿＿＿＿＿＿＿＿______|__　　 ',
　 　      ,′　 | ７ﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆ}  ,′
.　　     {　　　|/　}ﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆ{/ 　 　
*/
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower

using namespace std;

#define rep(a) _rep(0,int(a))
#define _rep(a,b) for(int i=int(a);i<int(b);i++)
#define ll long long
#define fst first
#define snd second


//factorial
int fact(int n) {
	int a = 1;
	for (int i = 1;i <= n;i++) a *= i;
	return a;
}

int a, b;
int main() {
	cin >> a >> b;
	cout << (a + b / 2) << endl;
}

