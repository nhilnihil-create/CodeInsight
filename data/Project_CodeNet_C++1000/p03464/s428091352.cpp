#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int S = (1 << 17);
ll k, tab[S], min_p, max_p;

int main(){
	
	cin >> k;
	for (int i = 1; i <= k; i ++)
		cin >> tab[i];
	min_p = max_p = 2;
	
	for (int i = k; i >= 1; i --){
		min_p = ((min_p - 1) / tab[i] + 1) * tab[i];
		max_p = max_p / tab[i] * tab[i] + tab[i] - 1;
	}
	if (max_p < min_p)
		cout << -1 << endl;
	else 
		cout << min_p << " " << max_p << endl;
	
	return 0;
}