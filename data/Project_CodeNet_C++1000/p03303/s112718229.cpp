#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)


// Write From This Line
int main()
{
	string s;
	cin >> s;
	int t;
	cin >> t;
	rep(i,s.size()) {
		if(i%t ==0){
			cout <<s[i];
		}
	}
	cout << endl;
}
