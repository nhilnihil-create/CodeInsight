#include <iostream>
#include <cmath>
#include <algorithm>
#include <string> //文字列
#include <iomanip> //doubleの桁数指定 setprecision()
#include <list> //前後に数値を入れれる配列
#include <map> //map
#include <vector> //vecror

#define REP(i,m,n) for(ll i = (ll) (m);i < (ll) (n);i++) //forの短縮
#define rep(i,n) REP(i,0,n) //REPが0の時
#define ll long long int

using namespace std;

double PI = acos(-1); //円周率
ll mod = 1e9 + 7;


//提出コード



ll r;


int main() {
	
	cin >> r;
	if (r < 1200) {
		cout << "ABC" << endl;
	}
	else if (r < 2800) {
		cout << "ARC" << endl;
	}
	else cout << "AGC" << endl;





	return 0;
}

