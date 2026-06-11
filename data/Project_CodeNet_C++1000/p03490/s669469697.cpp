#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Pi = pair < int, int >;
using Ti = pair < Pi , int >;

constexpr int INF = (1 << 30) - 1;
constexpr int dy[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
constexpr int dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

template < typename T > T gcd(T a, T b) { return ( b ? gcd(b, a % b) : a ); }
template < typename T > T lcm(T a, T b) { return ( a / gcd(a, b) * b ); }

int main()
{
	const int offset = 8500;
	string S;
	int x, y;
	vector < int > yoko, tate;

	bitset < 17000 > bp1, bp2;
	
	cin >> S >> x >> y;
	
	bool f = false;
	int cnt = 0;
	for ( int i = 0; i < S.size(); i++ ) {
		if ( S[i] == 'F' ) {
			cnt++;
		} else {
			if ( f ) tate.push_back(cnt);
			else     yoko.push_back(cnt);
			cnt = 0;
			f = !f;
		}
	}

	if ( f ) tate.push_back(cnt);
	else yoko.push_back(cnt);
	
	bp1[offset + yoko[0]] = true;
	bp2[offset] = true;

	for ( int i = 1; i < yoko.size(); i++ ) {
		bp1 = (bp1 << yoko[i]) | (bp1 >> yoko[i]);
	}

	for ( int i = 0; i < tate.size(); i++ ) {
		bp2 = (bp2 << tate[i]) | (bp2 >> tate[i]);
	}

	if ( bp1[offset + x] && bp2[offset + y] ) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return ( 0 );
}
