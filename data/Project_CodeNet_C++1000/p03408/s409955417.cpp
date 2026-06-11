#include <iostream>

using namespace std;

int main()
{
	int N, M;
	string s[100];
	string t[100];
	int YEN[100] = {0};
	int count_T[100] = {0};
	int max = 0;

	cin >> N;	
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		s[i] = tmp;
	}	

	cin >> M;	
	for (int i = 0; i < M; i++) {
		string tmp;
		cin >> tmp;
		t[i] = tmp;
	}

	for (int i = 0; i < N; i++) {
		for (int j =0; j < N; j++) {
			if (s[i] == s[j]) {
				YEN[i]++;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j =0; j < M; j++) {
			if (t[i] == t[j]) {
				count_T[i]++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (s[i] == t[j]) {
				YEN[i]--;	
			}
		}
	}
	for (int i = 0; i < N; i++) {
		// cout << s[i] << "の値段" << YEN[i] << "円\n";
		if (YEN[i]	> max) 
			max = YEN[i];
	}
	cout << max << '\n';
}