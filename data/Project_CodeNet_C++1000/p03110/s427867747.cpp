#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	long double JPY=0;
	long double BTC=0;
	
	for(int i=0;i<n;i++){
		long double mn;
		string cur;
		cin>>mn>>cur;
		if(cur=="JPY") JPY+=mn;
		else BTC+=mn;
	}
	JPY += BTC*380000.0;

	cout << JPY << endl;
}