
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
long long int a[200001];
long long int S[200001];
int main() {


	int n;
	int i;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	S[0] = 0;
	for (i = 0; i < n; i++) {
		S[i + 1] = S[i] + a[i];
	}
	long long int MIN = 10000000000000000;
	long long int pq, rs, pqrs[4];
	long long int x, y, z;
	int left, right, mid, mid2;
	for (i = 2; i < n - 1; i++) {
		pq = S[i];
		rs = S[n] - S[i];
	
		left = 0;
		right = i;
		while (1) {
			mid = (left + right) / 2;
			x = abs((S[i] - S[mid - 1]) - S[mid - 1]);
			y = abs((S[i] - S[mid]) - S[mid]);
			z = abs((S[i] - S[mid + 1]) - S[mid + 1]);
			if (x < y && y < z) {
				right = mid;
			}
			else if (x > y && y > z) {
				left = mid;
			}
			else {
				break;
			}
		}

		left = i;
		right = n;

		while (1) {
			mid2 = (left + right) / 2;
			x = abs((S[n] - S[mid2 - 1]) - (S[mid2 - 1] - S[i]));
			y = abs((S[n] - S[mid2]) - (S[mid2] - S[i]));
			z = abs((S[n] - S[mid2 + 1]) - (S[mid2 + 1] - S[i]));
			if (x < y && y < z) {
				right = mid2;
			}
			else if (x > y && y > z) {
				left = mid2;
			}
			else {
				break;
			}
		}

		pqrs[0] = S[mid];
		pqrs[1] = S[i] - S[mid];
		pqrs[2] = S[mid2] - S[i];
		pqrs[3] = S[n] - S[mid2];
		//cout << pqrs[0] << ' ' << pqrs[1] << ' ' << pqrs[2] << ' ' << pqrs[3] << endl;
		sort(pqrs, pqrs + 4);
		if (MIN > pqrs[3] - pqrs[0])MIN = pqrs[3] - pqrs[0];
	
	}
	cout << MIN << endl;
	return 0;



	/*int i;
	long long int n;
	cin >> n;
	long long int sum = 0;
	for (i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = a[i] - (i + 1);
		//sum = sum + a[i] - i;
	}
	sort(a, a + n);
	//long long int b = sum / n;
	//int j;
	//long long int sum2 = 0;
	//sum = 10000000000000000;
	
	//for (j = b - 10000; j <= b + 10000; j++) {

	//	sum2 = 0;
		for (i = 0; i < n; i++) {
			sum = sum + abs(a[i] - a[n / 2]);
		}
	//	sum = min(sum, sum2);
	//}
		
	
	cout << sum << endl;
	return 0;
	*/
	

}