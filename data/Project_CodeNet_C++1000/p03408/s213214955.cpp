#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	cin >> n;
	vector<string> blue(n);

	for(int i=0; i<n; i++)
	cin >> blue.at(i);
	
	cin >> m;
	vector<string> red(m);

	for(int i=0; i<m; i++)
	cin >> red.at(i);

int r=0, b=0;
	for(int i=0; i<n; i++){
		b = 0;
		for(int j=0; j<n; j++){
			if(blue.at(i) == blue.at(j)){
				b++;
			}
		}
		for(int j=0; j<m; j++){
			if(blue.at(i) == red.at(j)){
				b--;
			}
		}
		if(b>r){
			r = b;
		}
	}

	cout << r << endl;

}