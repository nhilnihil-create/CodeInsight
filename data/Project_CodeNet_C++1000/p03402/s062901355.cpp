# include <bits/stdc++.h>
 
using namespace std;

char g[107][107];

void fill( char c ) {
	for ( int i = 0; i < 107; i++ ) {
		for ( int j = 0; j < 107; j++ ) {
			g[i][j] = c;
		}
	}   
}

int main() {
	//freopen("out.txt", "w", stdout);
	int a, b;
	cin >> a >> b;
	if ( a == 1 && b == 1 ) {
		cout << "2 2\n";
		cout << "#.\n";
		cout << "..";
		return 0;
	}
	if ( a >= b ) {
		fill( '.' );
		int cnt = 0, ind = 0;
		for ( int j = 2; j <= 99; j += 2 ) {
			for ( int i = 2; i <= 98; i += 2 ) {
				if ( cnt == a - 1 ) {
					break;
				}
				g[i - 1][j] = '#';
				g[i - 1][j + 1] = '#';
				g[i][j + 1] = '#';
				g[i + 1][j] = '#';
				g[i + 1][j + 1] = '#';
				cnt++;
				if ( j == 2 )
					ind = i + 1;
			}
		}
		for ( int i = 1; i <= ind; i++ ) {
			g[i][1] = '#';
		}
		b--;
		for ( int i = 1; i <= 100; i++ ) {
			for ( int j = 1; j <= 100; j++ ) {
				if ( !b ) break;
				if ( g[i - 1][j - 1] != '#' && g[i - 1][j] != '#' &&
					g[i - 1][j + 1] != '#' && g[i][j - 1] != '#' &&
					g[i][j] != '#' && g[i][j + 1] != '#' && g[i + 1][j - 1] != '#' &&
					g[i + 1][j] != '#' && g[i + 1][j + 1] != '#' ) {
					g[i][j] = '#';
					b--;
				}
			}
			if ( !b ) break;
		}
	}
	else {
		fill( '#' );
		int cnt = 0, ind = 0;
		for ( int j = 2; j <= 99; j += 2 ) {
			for ( int i = 2; i <= 98; i += 2 ) {
				if ( cnt == b - 1 ) {
					break;
				}
				g[i - 1][j] = '.';
				g[i - 1][j + 1] = '.';
				g[i][j + 1] = '.';
				g[i + 1][j] = '.';
				g[i + 1][j + 1] = '.';
				cnt++;
				if ( j == 2 )
					ind = i + 1;
			}
		}
		for ( int i = 1; i <= ind; i++ ) {
			g[i][1] = '.';
		}
		a--;
		for ( int i = 1; i <= 100; i++ ) {
			for ( int j = 1; j <= 100; j++ ) {
				if ( !a ) break;
				if ( g[i - 1][j - 1] != '.' && g[i - 1][j] != '.' &&
					g[i - 1][j + 1] != '.' && g[i][j - 1] != '.' &&
					g[i][j] != '.' && g[i][j + 1] != '.' && g[i + 1][j - 1] != '.' &&
					g[i + 1][j] != '.' && g[i + 1][j + 1] != '.' ) {
					g[i][j] = '.';
					a--;
				}
			}
			if ( !a ) break;
		} 
	}
	cout << "100 100\n";
	for ( int i = 1; i <= 100; i++ ) {
		for ( int j = 1; j <= 100; j++ ) {
			cout << g[i][j];
		}
		cout << '\n';
	}
}