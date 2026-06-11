#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; int t;
	cin >> n;
	cin >> t;
	int aux1, aux2;
	int costAux = 1001;
	while(n--){
		cin >> aux1;
		cin >> aux2;
		if(aux2 <= t) {
			if(aux1 < costAux) {
				costAux = aux1;
			}		
		}
	}
	if(costAux == 1001) cout << "TLE"; else cout << costAux;
	return 0;
}