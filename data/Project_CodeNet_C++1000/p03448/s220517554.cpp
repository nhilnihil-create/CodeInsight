#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
	int a,b,c,x;
	cin >> a >> b >> c >> x;
	int counter=0;
	rep(i,a+1){
		rep(j,b+1){
			rep(k,c+1){
				int m = 500*i + 100*j + 50*k ;
				if(m == x) {
					counter++;
				}
				if(m>=x) break;

			}
		}
	}
	cout << counter << endl;
}
