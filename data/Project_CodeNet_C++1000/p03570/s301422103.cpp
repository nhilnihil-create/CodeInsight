# include <bits/stdc++.h>

inline void smin ( int& d, const int& x )  {
	( d > x ) ? d = x : 0 ;
}

using namespace std ;

char s [234567] ;

unordered_map < int, int > dp ;

const int N = 1 << 26 ;

//bitset < N > vis ;

int main ( )  {
	scanf ( "%s", s ) ;
	int stat = 0 ;
	int l = strlen ( s ) ;
	dp [0] = 0 ;
	for ( int i = 0 ; i < l ; ++ i ) {
		stat ^= ( 1 << ( s [i] - 'a' ) ) ;
		int trans = INT_MAX ;
		for ( int j = 0 ; j < 26 ; ++ j ) {
			auto k = dp.find ( stat ^ ( 1 << j ) ) ;
			if ( k != dp.end ( ) ) smin ( trans, k -> second ) ;
		}
		auto k = dp.find ( stat ) ;
		if ( k != dp.end ( ) )  smin ( k -> second, trans + 1 ) ;
		else dp [stat] = trans + 1 ;
	}
	if ( ! stat || __builtin_popcount ( stat ) == 1 ) return cout << 1 << endl, 0 ;
	return cout << dp [stat] << endl, 0 ;
}
