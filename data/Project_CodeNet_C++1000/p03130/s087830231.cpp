#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	
	vector<int> P(4);
	for(int i = 0; i < 3; i++){
		int a, b;
		cin >> a;
		P[--a]++;
		cin >> b;
		P[--b]++;
	}		

	sort(P.begin(), P.end(), greater<int>());
//	for(int i = 0; i < 4; i++) cout << P[i] << endl;
	if(P[0] > 2 || P[3] == 0) cout << "NO" << endl;
	else cout << "YES" << endl;
}