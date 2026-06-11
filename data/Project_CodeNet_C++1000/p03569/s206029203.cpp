#include <iostream>
using namespace std;

int main(){
	string s;
	cin >> s;
	int f = 0;
	int b = s.size() - 1;
	
	int ans = 0;
	while( f < b ){
	 	if( s[f] != s[b] ) {
	 		if( s[f] == 'x' || s[b] == 'x' ){
	 			ans ++;
	 			if( s[f] == 'x' ){
	 				f++;
	 			}else{
	 				b--;
	 			}
	 		}else{
	 			cout << -1 << endl;
	 			return 0;
	 		}
	 	}else{
	 		f++;
	 		b--;
 		}
	}
	cout << ans << endl;
}