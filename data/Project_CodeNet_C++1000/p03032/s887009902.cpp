#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
using namespace std;
int main() {

	//D

	int v[52];
	int n, k;
	cin >> n >> k;
	int i;
	v[0] = 0;
	for (i = 1; i <= n; i++) {
		cin >> v[i];
	}
	v[n + 1] = 0;
	int Lj[52];
	int Rj[52];
	Lj[0] = 0;
	for (i = 1; i <= n+1; i++) {
		Lj[i] = Lj[i - 1] + v[i];
	}
	Rj[n + 1] = 0;
	for (i = n; i >= 0; i--) {
		Rj[i] = Rj[i + 1] + v[i];
	}
	int sum = 0;
	for (i = 0; i <= n + 1; i++)sum += v[i];
	int max = 0;

	priority_queue<int> equeue;
	int j;
	int krem, l, sumcheck;
	for (i = 0; i <= n; i++) {
		for (j = i + 1; j <= n + 1; j++) {
			if (i + (n + 1 - j) <= k) {//k回以下しか取ってはいけない．
				krem = k - (i + (n + 1 - j));
				sumcheck =  Lj[i] + Rj[j];
				for (l = 0; l <= i; l++) {
					equeue.push(-v[l]);
				}
				for (l = n + 1; l >= j; l--) {
					equeue.push(-v[l]);
				}
				for (l = 0; l < krem; l++) {
					if (equeue.size() > 0) {
						if (equeue.top() > 0) {
							sumcheck = sumcheck + equeue.top();
							equeue.pop();
						}
						else { break; }
					}
					else { break; }
				}
				if (sumcheck > max) {
					max = sumcheck;
					//cout << sumcheck << ' ' << i << ',' << j << endl;
				}
				while (equeue.size())equeue.pop();
			}
			
		}
	}
	cout << max << endl;
	return 0;

	//C
	/*int n, m;
	cin >> n >> m;
	int k,s ;
	int i, j;
	int comb[11][11];
	for (i = 0; i < 11; i++) {
		for (j = 0; j < 11; j++) {
			comb[i][j] = 0;
		}
	}
	for (i = 1; i <= m; i++) {
		cin >> k;
		for (j = 0; j < k; j++) {
			cin >> s;
			comb[i][s] = 1;
		}
	}
	int p[11];
	for (i = 1; i <= m; i++) {
		cin >> p[i];
	}
	int bin[11] = { 0,1,2,4,8,16,32,64,128,256,512 };
	int ii;
	int counter = 0;
	int bcheck;
	int bflag;
	for (i = 0; i < bin[n]*2; i++) {
		bflag = 0;
		for (ii = 1; ii <= m; ii++) {
			bcheck = 0;
			for (j = 1; j <= n; j++) {
				if ((i ^ bin[j]) != i + bin[j]) {
					bcheck = bcheck + comb[ii][j];
				}
			}
			if (bcheck % 2 != p[ii]) {
				bflag = 1;
			}

		}
		if (bflag == 0) {
			counter++;
		}
	}
	cout << counter << endl;
	return 0;
	*/




	//B
	/*string  s[100];
	//cin >> s >> t;
	int n;
	int p[100];
	cin >> n;
	int i;
	int num[100];
	for (i = 0; i < n; i++) {
		cin >> s[i] >> p[i];
		num[i] = i + 1;
	}

	string ss;
	int pp;
	int j;
	for (i = n-1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (s[j] > s[j + 1]) {
				ss = s[j];
				s[j] = s[j + 1];
				s[j + 1] = ss;
				pp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = pp;
				pp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = pp;
			}
			else if((s[j] == s[j+1]) && (p[j] < p[j+1])){
				pp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = pp;
				pp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = pp;
			}
		}
	}
	for (i = 0; i < n; i++) {
		cout << num[i] << endl;
	}
	return 0;
	//if (s < t) {
	//	cout << s;
	//}
	//else {
	//	cout << t;
	//}
	return 0;
	*/

	//A

	/*int a, p;
	cin >> a >> p;
	p = p + a * 3;
	cout << (p - (p % 2)) / 2 << endl;
	return 0;*/



}