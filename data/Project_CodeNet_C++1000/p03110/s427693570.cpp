#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	double yen = 0.0;
	for(int i=0; i<n; i++){
		double x;
       		string u;
		cin >> x >> u;
		
		if(u=="JPY") yen += x;
		else yen += 380000.0*x;
	}
	cout << yen << endl;
	return 0;
}