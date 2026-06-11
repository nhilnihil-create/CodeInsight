#include <bits/stdc++.h>
#define INF (1<<30)
#define MOD 1000000007
#define l_ength size
#define RIGHT " → "
using ll = long long;
using namespace std;

ll gcd( ll x, ll y ){
	return ( y == 0 ) ? x : gcd( y, x%y );
}

int main(){
	int t; cin >> t;
	while( t-- ){
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		bool schleife;
		/*
		b > d : 購入ペースのほうが早いのでなくなる
		b > a : 最初の時点で購入不可
		c >= b : 購入すると必ず補充ゾーンに入る
		*/
		if( b > d || b > a ){
			schleife = false;
		} else if( c >= b ){
			schleife = true;
		} else {
			/*
			現在の本数を s とすると s = a%b-b*m+d*n と表せ，これを最大公約数でくくると s = a%g-k*g となる
			s が c より大きいとき（補充されない）で s-b < 0（購入するとマイナスになる）となるような場合
			次の購入でジュースがなくなってしまうので No
			これをまとめると c < s における s において s < b のときジュースがなくなる
			s の最小値についてこの範囲に含まれているかどうか考えれば判定可能
			m = a%g-k*g とおくと c < s から k = ceil( (c-a%g+1)/g ) と求まる
			*/
			ll g = gcd( b, d );
			schleife = ( a%g + g*((c-a%g+g)/g) < b ) ? false : true;
		}
		cout << ( schleife ? "Yes" : "No" ) << endl; 
	}
	return 0;
}

/*
	// シミュレーション用
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int n = 20;
	cout << a << RIGHT;
	int cur = a;
	while( n-- ){
		cur -= b;
		if( cur < 0 ){
			cout << "verkauft" << endl;
			return 0;
		} else {
			cout << cur << RIGHT;
			( cur > c ) ?: ( cur += d );
			cout << cur << RIGHT;
		}
	}
	cout << "......" << endl;
*/