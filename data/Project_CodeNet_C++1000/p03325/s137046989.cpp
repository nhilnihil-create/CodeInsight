#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0 ; i <n; i++){
		cin >> arr[i];
	}
	int count = 0;
	for(int i = 0; i < n;i++){
		if (arr[i] % 2 == 0){
			while (arr[i] % 2 == 0){
				arr[i] = arr[i] * 3;
				arr[i] = arr[i] / 2;
				count++;
			}
		}
		else {
			continue;
		}
	}

cout << count << endl;
}
