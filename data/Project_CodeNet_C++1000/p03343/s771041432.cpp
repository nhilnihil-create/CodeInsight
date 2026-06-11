#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<vector>
using namespace std;
int E[300000], W[300000];
int A[200000], B[200000][20];
int C[2000];
int main() {

	/*int n;
	string s;
	cin >> n;
	cin >> s;
	int i;
	int e = 0, w = 0;
	for (i = 0; i < n; i++) {
		if (s[i] == 'E') {
			e++;
		}
		else {
			w++;
		}
		E[i] = e; W[i] = w;
	}
	int MIN = E[n - 1] - E[0];
	for (i = 1; i < n; i++) {
		
		if (MIN > W[i - 1] + E[n - 1] - E[i]) {
			MIN = W[i - 1] + E[n - 1] - E[i];
		}
	}
	cout << MIN << endl;
	return 0;*/

	/*int n;
	cin >> n;
	long long int i, j, a;
	int bin[21];
	bin[0] = 1;
	for (i = 1; i < 21; i++) {
		bin[i] = bin[i - 1] * 2;
	}
	for (i = 0; i < n; i++) {
		cin >> A[i];
		a = A[i];
		j = 0;
		while (a > 0) {
			if (a % 2 == 1) {
				B[i][j] = 1;
			}
			else {
				B[i][j] = 0;
			}
			a = a / 2;
			j++;
		}
	}
	long long int sum = 0;
	i = 0; j = 0;
	int k, c[20], flag;
	for (k = 0; k < 20; k++)c[k] = B[0][k];
	while (1) {
		flag = 0;
		for (k = 0; k < 20; k++) {

			if (c[k] > 1)flag = 1;
		}
		if (flag == 1) {
			//j動かす
			j++;
			for (k = 0; k < 20; k++) {
				if (B[j - 1][k] == 1)c[k]--;
			}
			//if (j == i)sum++;
			//if (j == n - 1) {
			//	cout << sum << endl;
			//	return 0;
			//}
		}
		else {
			//i動かす
			sum = sum + i - j + 1;
			if (i == n - 1) {
				cout << sum << endl;
				return 0;
			}
			//cout << sum << endl;
			i++;
			for (k = 0; k < 20; k++) {
				if (B[i][k] == 1)c[k]++;
			}
			//if (i == n - 1) {
			//	flag = 0;
			//	for (k = 0; k < 20; k++) {
					
			//		if (c[k] > 1)flag = 1;
			//	}
			//	cout << sum + flag * (i - j + 1) << endl;
			//	return 0;
			//}
		}
		//cout << "i = " << i << ": j = " << j << endl;
	}*/

	int n, k, q;
	cin >> n >> k >> q;
	int i, j, l;
	for (i = 0; i < n; i++) {
		cin >> A[i];
	}
	//sort(A, A + n);
	//for (i = 0; i < n; i++)cout << A[i] << ' ';
	//cout << endl;
	int MIN = 1000000001, left, right, ct;
	priority_queue<int, vector<int>, greater<int>> que, que2;
	for (i = 0; i < n; i++) {

		//A[i]を選べるかどうか
		//ct = 1;
		//j = i - 1;
		//while (j >= 0 && ct < k) {
		//	if (A[j] >= A[i]) {
		//		ct++;
		//		j--;
		//	}
		//	else {
		//		break;
		//	}
		//}
		//j = i + 1;
		//while (j <= n - 1 && ct < k) {
		//	if (A[j] >= A[i]) {
		//		ct++;
		//		j++;
		//	}
		//	else {
		//		break;
		//	}
		//}
		
		left = -1;
		A[n] = -1;
		for (j = 0; j <= n; j++) {
			if (A[j] < A[i]) {
				right = j;
				//cout << "i = " << i << ": left = " << left << ": right = " << right << endl;
				if (right - left - 1 >= k) {
					//cout << 1 << endl;
					for (l = left + 1; l < right; l++) {
						que.push(A[l]);
						//cout << A[l] << endl;
					}
					for (l = 0; l <= right - left - 1 - k; l++) {
						que2.push(que.top());
						//cout << que.top() << endl;
						que.pop();
					}
				}
				left = j;
				while (que.size())que.pop();
			}
		}

		if (que2.size() >= q) {
			if (que2.top() == A[i]) {
				for (j = 0; j < q - 1; j++)que2.pop();
				if (que2.top() - A[i] < MIN)MIN = que2.top() - A[i];
			}
		}
		while (que2.size())que2.pop();

	}
	
	
	//for (i = 0; i <= n - q; i++) {
	//	if (A[i + q - 1] - A[i] < MIN)MIN = A[i + q - 1] - A[i];
	//}
	cout << MIN << endl;
	return 0;






}