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
	int h1,h2,w1,w2;
	cin >> h1 >> w1 >> h2 >> w2;
	cout << (h1-h2)*(w1-w2) << endl; 
}