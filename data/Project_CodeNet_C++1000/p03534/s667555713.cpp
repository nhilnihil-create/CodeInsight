#include <bits/stdc++.h>
using namespace std;

typedef long long int ll ;

ll gcd(ll aaa,ll bbb) {
    if(bbb==0) {
        return aaa;
    }
    return gcd(bbb,aaa%bbb);
}

ll lcm(ll m,ll n)
{
    if ( ( 0 == m ) || ( 0 == n ) )
        return 0;

    return ((m / gcd(m, n)) * n);
}

int main() { 

	string S;
	cin >> S;
	long a[3]={},isa=0;

	for(long i = 0; i < S.size(); i++) {
		if(S[i] == 'a') {
			a[0]++;
		}else if(S[i] == 'b') {
			a[1]++;
		}else {
			a[2]++;
		}
	}

	sort(a,a+3);
	reverse(a,a+3);
	isa += a[0] - a[1];
	isa += a[0] - a[2];
	if(isa > 2) {
		cout << "NO" << endl;
	}else {
		cout << "YES" << endl;
	}
	return 0;
}
