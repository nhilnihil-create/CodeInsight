#include <bits/stdc++.h>
using namespace std;

int main()
{

	int A_yen;
	int B_yen;
	int C_yen;   // 2 C_yen で  Aピザ1枚  Bピザ1枚  (ABセット)
	int X;
	int Y;
	
	int price = 2147483647;

	cin >> A_yen >> B_yen >> C_yen >> X >> Y;
	
	
	// ABセットをiセット買うときを考える
	for (int i = 0; i <= 100000; i++) {

		price = min(price, 2 * C_yen * i + A_yen * max(0, X - i) + B_yen * max(0, Y - i) );		

	}
		
	cout << price <<  endl;

	return 0;
}