#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,t,a;
	cin >> n >> t >> a;
	
	int candy = 0;
	double k = 1e9+7;
	for(int i=0; i<n; i++){
		int h;
		cin >> h;
		double T = t-h*0.006;
		if(abs(a-T) < abs(a-k)){
			k = T;
			candy = i+1;
		}
	}

	cout << candy << endl;
	return 0;
}