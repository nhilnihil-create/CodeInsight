#include <bits/stdc++.h>
using namespace std;
const int M=10100;
int h[M],n,ans=0;
int main(){
	cin >> n ;
	for ( int i = 0 ; i < n ; i ++ ){
		cin >> h [ i ] ;
	}
	while (1) {
        int tmp = 0;
        for ( int i = 0 ; i < n ; i ++ ) {
            if (h[i] > 0) {
                tmp++;
                while (i < n && h[i] > 0) {
                    h[ i ] --;
                    i ++;
                }
            }
        }
        if (tmp == 0) break;
        ans += tmp;
    }
    
    cout << ans;
    return 0;
}