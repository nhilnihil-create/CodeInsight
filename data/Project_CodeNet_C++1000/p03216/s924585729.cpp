#include <iostream>
using namespace std;

int main() {
	int n;
	string s;
	int q;
	int k;
	
	cin >> n >> s >> q;
	for(int times = 0; times < q; times++){
		cin >> k;
		long int r = 0;
		long int nowd = 0;
		long int nowm = 0;
		long int nowdm = 0;
		for (int i = 0; i < n; i++){
			if(s[i] == 'D'){nowd++;}
			if(s[i] == 'M'){nowm++; nowdm += nowd;}
			if(s[i] == 'C'){r += nowdm;}
			if(i >= k-1){
				if(s[i-k+1] == 'D'){nowd--; nowdm -= nowm;}
				if(s[i-k+1] == 'M'){nowm -= 1;}
			}
		}
		cout << r << endl;
	}
	return 0;
}