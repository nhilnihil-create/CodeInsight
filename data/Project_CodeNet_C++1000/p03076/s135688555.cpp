#include <bits/stdc++.h>
using namespace std;

int main() {
	int n[5];
	int x[5];
	int ans = 0, may = 0;
	
	for(int i = 0; i<5; i++)
		cin >> n[i];
		
	for(int i = 0; i<5; i++){
		x[i] = 0;
		int aux = n[i];
		while(aux%10 != 0){
			aux++;
			x[i]++;
		}
		may = max(may,x[i]);
	}
	
	for(int i = 0; i<5; i++){
		if(x[i] == may){
			ans += n[i];
			may = -1;
		}
		else
			ans += n[i] + x[i];
	}
	cout << ans << endl;
	return 0;
}