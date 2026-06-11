#include <bits/stdc++.h>
using namespace std;

int main(){

	string s, c = "01"; 
	int cont0 = 0, cont1 = 0;
	cin >> s;
	
	for(auto i : s){

		if (i==c[0]) cont0++;
		else cont1++;
	}
	printf("%d\n", 2*min(cont0,cont1));
	return 0;
}
