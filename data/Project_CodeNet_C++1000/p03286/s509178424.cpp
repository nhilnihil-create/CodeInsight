#include <bits/stdc++.h>
using namespace std;
// -9 = 1011
// (1)+(-2)+(-8)
//　はじめ-9                       //はじめ８ == 11000
//  -9%2 == 1 ans+=1 -9 = -10 = 5 //8%2 == 0 8 = -4
//  5%2 == 1 ans+=1 5 = 4 = -2    //-4%2 == 0 -4 = 2
// -2%2 == 0 ans+=0 -2 == 1;      //2%2 == 0 2 = -1
int main() {                      //-1%2 == 1 ans+=1 -1 = -2 = 1 
	int N;
	cin >> N;
    if(N == 0) {
        cout << 0 << endl;
        return 0;
    }
	string ans = "";
	while (N != 0) {
		if (N%2 != 0) {
            N--;
			ans = '1' + ans;
		}
		else {
            ans = '0' + ans;
        }
		N/=-2;
	}
	cout << ans << endl;
}