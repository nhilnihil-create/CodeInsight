#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//cout << fixed << setprecision(15);
vector<int> forintinput(int n) {
	vector<int> x;
	for(int i = 0;i < n;i++){
		int ia;
		cin >> ia;
		x.push_back(ia);
	}
	return x;
}
int main(){
	char b;
	cin >> b;
	if(b == 'A'){
		cout << 'T' << endl;
	}else if(b == 'C'){
		cout << 'G' << endl;
	}else if(b == 'G'){
		cout << 'C' << endl;
	}else if(b == 'T'){
		cout << 'A' << endl;
	}
}