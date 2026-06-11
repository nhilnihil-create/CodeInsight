#include <bits/stdc++.h>
using namespace std;

int main(){
	int coin500, coin100, coin50, x;
	cin >> coin500 >> coin100 >> coin50 >> x;
	int pattern = 0;
	for(int num500=0; num500<=coin500; ++num500){
		int money500 = 500*num500;
		if(money500 > x) break;
		for(int num100=0; num100<=coin100; ++num100){
			int money100 = money500 + 100*num100;
			if(money100 > x) break;
			for(int num50=0; num50<=coin50; ++num50){
				int money = money100 + 50*num50;
				if(money > x) break;
				if(money == x) pattern ++;
			}
		}
	}
	cout << pattern << endl;
	return 0;
}
