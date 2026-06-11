#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int A,B;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> A >> B;

	cout << 100 << " " << 100 << endl;

	int cnt = 0;
	for (int i = 0;i < 50;i++){
		for (int j = 0;j < 100;j++){
			if(i%2 == 0 && j%2 == 0 && cnt < A-1){
				cout << ".";
				cnt++;
			}
			else cout << "#";
		}
		cout << endl;
	}

	cnt = 0;
	for (int i = 0;i < 50;i++){
		for (int j = 0;j < 100;j++){
			if(i%2 == 1 && j%2 == 0 && cnt < B-1){
				cout << "#";
				cnt++;
			}
			else cout << ".";
		}
		cout << endl;
	}


	return 0;

}
