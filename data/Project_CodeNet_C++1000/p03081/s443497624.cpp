#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
	int N, Q;
	cin >> N >> Q;
	string s;
	cin >> s;
	vector<char> t(Q), d(Q);
	for (int i = 0; i < Q; i++){
		cin >> t[i] >> d[i];
	}
	int t1 = -1;
	int f1 = N;
	while (f1 - t1 > 1){
		int mid = (t1 + f1) / 2;
		int pos = mid;
		for (int i = 0; i < Q; i++){
			if (s[pos] == t[i]){
				if (d[i] == 'L'){
					pos--;
				} else {
					pos++;
				}
			}
			if (pos == -1 || pos == N){
				break;
			}
		}
		if (pos == -1){
			t1 = mid;
		} else {
			f1 = mid;
		}
	}
	int t2 = N;
	int f2 = -1;
	while (t2 - f2 > 1){
		int mid = (t2 + f2) / 2;
		int pos = mid;
		for (int i = 0; i < Q; i++){
			if (s[pos] == t[i]){
				if (d[i] == 'L'){
					pos--;
				} else {
					pos++;
				}
			}
			if (pos == -1 || pos == N){
				break;
			}
		}
		if (pos == N){
			t2 = mid;
		} else {
			f2 = mid;
		}
	}
	cout << t2 - t1 - 1 << endl;
}