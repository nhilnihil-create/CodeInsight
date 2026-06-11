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

//保留所有权利。
#include<iostream>
#include<stdio.h>//printするよ
#include<vector>
#include<algorithm>//辞書順はnext_permutationだよ
#include<set>
#include<string>
#include<sstream>
#include<string.h>
#include<complex>
#include<time.h>
#include<random>
#include<cmath>
#include<math.h>
#include<queue>
#include<time.h>
#include<iomanip>
#include<locale>
#include<utility>//swapで数値交換するよ
//END OF LIBRARIES.
#define rt "\n"//改行を最速化させるよ
#define rep(i,n) for(int i=0;i<n;i++)
#define rop(i,n) for(int i=1;i<=n;i++)
#define drep(i,n) for(int i=n-1;0<=i;i--)
#define drop(i,n) for(int i=n;0<i;i--)
#define yes(ans) if(ans)cout<<"yes"<<rt;else cout<<"no"<<rt;
#define Yes(ans) if(ans)cout<<"Yes"<<rt;else cout<<"No"<<rt;
#define YES(ans) if(ans)cout<<"YES"<<rt;else cout<<"NO"<<rt;
#define sec(a,b,ans) if(ans)cout<<a<<rt;else cout<<b<<rt;
#define vcin(s,n) rep(i,n)cin>>s[i];//vcin(配列名),(繰り返し回数)
#define sort(s) sort(s.begin(),s.end())
#define reve(s) reverse(s.begin(),s.end())
#define asas int ans=0
#define llcncn llint cnt=0
#define llasas llint ans=0
#define str string
#define please return
#define AC 0//おまじないだよ
#define Rapid cin.tie(0);ios::sync_with_stdio(false)
#define Pi 3.1415926535897932384626
//END OF DEFINE.
using namespace std;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef vector<char> vchar;
typedef vector<double> vdou;
typedef long long int llint;
typedef pair<int, int> pint;
typedef pair<llint, llint> pllint;
typedef vector<llint> vllint;
typedef vector<pint> vpint;
typedef vector<pair<llint, llint>> vpllint;
typedef vector<vector<int>> vvint;
typedef vector<vector<char>> vvchar;
typedef vector<vector<llint>> vvllint;
typedef vector<vector<string>> vvstr;
typedef vector<vector<bool>> vvbool;
typedef vector<vector<pint>> vvpint;
typedef vector<bool> vbool;
//printf("%02d:%02d:%02d\n", h, m, s);・・・2文字は埋める・h、m、ｓ
//END OF TYPEDEF.

//最大公約数（GCD）を求めるよ
//最小公倍数（LCM）は＜＜　A × B ÷ GCD　 ＞＞で求まるよ

long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}
long long LCM(long long a, long long b) {
	return a * b / GCD(a, b);
}
unsigned GetDigit(unsigned num) {
	return std::to_string(num).length();
}
int tow(int n) {//2のn乗を求めるらしい
	if (n == 0)return 1;
	int x = tow(n / 2);
	x *= x;
	if (n % 2 == 1)x *= 2;
	return x;
	//dominoに借りたやつです
}
/*
  for A以上B未満でI探索 for (int I = A; i <= B; i++)

  string s = to_string(i);　iをstringでsに変換

  char　小文字のほうが32大--------------------大文字と小文字の境=93

  大文字→小文字 文字列のn文字目を大文字で出力→ (char)toupper(a[n])

  pow(a,b) → aのb乗を求める

  s1.erase(n) 文字列s1の、n文字目以降削除
  */
int a=0, b=0, c = 0;
string s = "";

int main(void) {
	//vector,set,map,stack,queue,deque,priority_queue

	llint a, b, c, k;
	cin >> a >> b >> c >> k;
	if (k % 2 == 0)cout << a - b << rt;
	else cout << b - a << rt;

	please AC;
}