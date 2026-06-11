#include <bits/stdc++.h>
using namespace std;
int t[1000100] , s;
int zhuan (int a){
	if ( a % 2 == 0 ) return a / 2;
	else return a * 3 + 1;
}

int main(){
	cin >> s ;
	t [ s ] ++ ;
	int x = s ;
	int cnt = 2;
	while ( 1 ){
		x = zhuan ( x );
		if ( t [ x ] ){
			cout << cnt << endl;
			return 0;
		}
		t[ x ] ++ ;cnt ++;
	}
}