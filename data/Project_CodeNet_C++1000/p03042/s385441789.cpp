#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	int s;
	cin >> s;

	int fir = s/100;
	int sec = s%100;

	if(1 <= fir && fir <= 12){
		if(1 <= sec && sec <= 12) cout << "AMBIGUOUS" << endl;
		else cout << "MMYY" << endl;
	}else if(1 <= sec && sec <= 12){
		cout << "YYMM" << endl;
	}else cout << "NA" << endl;

	return 0;
}