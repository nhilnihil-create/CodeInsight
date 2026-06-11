#include <bits/stdc++.h>
using namespace std;


#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ll long long


int soma_digitos( int x ) {
	string n = to_string(x);
	int s = 0;
	for ( int i = 0; i < n.size(); i++ ) {
		s += n[i] - '0';
	}
	return s;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a, b, soma, menor = 1e5;
    cin >> n;

    for ( int i = 1; i < n / 2 + 2; i++ ) {
    	a = i;
    	b = n - i;
    	soma = soma_digitos(a);
    	soma += soma_digitos(b);
    	if ( soma < menor ) {
    		menor = soma;
    	}
    }

    cout << menor << endl;

    return 0;
}
