#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
	int R,G,B,N,r=0;
	cin >> R >> G >> B >> N;

	rep(i,N/R+1)
		rep(j,(N-R*i)/G+1)
			if((N-R*i-G*j)%B == 0)
				++r;
	cout << r << endl;

	return 0;
}
