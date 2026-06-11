#include<iostream>
using namespace std;
int main() {
	
	//D
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	int seq[100001];
	int i;
	for (i = 0; i < 100001; i++) {
		seq[i] = 0;
	}
	int seqnum = 0;
	if (s[0] == '0') {
		seq[0] = 0;
		seqnum++;
	}
	i = 0;
	int counter = 0;
	int maxcounter;
	char seqnow = s[0];
	while (i < s.length()) {
		if (s[i] == seqnow) {
			seq[seqnum]++;
		}
		else {
			seqnum++;
			seqnow = s[i];
			seq[seqnum]++;
			//seqnum++;
		}
		i++;
	}
	//for (i = 0; i <= seqnum; i++) {
	//	cout << seq[i] << endl;
	//}
	seq[seqnum + 1] = 0;
	if (k >= (seqnum + (seqnum % 2)) / 2) {
		cout << s.length() << endl;
		return 0;
	}
	else {
		for (i = 0; i <= 2 * k; i++) {
			counter = counter + seq[i];
			//cout << counter << endl;
		}
		maxcounter = counter;
		for (i = 0; i < (seqnum + (seqnum % 2)) / 2 - k; i++) {
			counter = counter - seq[i * 2] - seq[i * 2 + 1];
			counter = counter + seq[i * 2 + 2 * k + 1] + seq[i * 2 + 2 * k + 2];
			//cout << counter << endl;
			if (maxcounter < counter)maxcounter = counter;
		}
		cout << maxcounter << endl;
		return 0;
	}

	//C
	/*string s;
	int i;
	int counter1 = 0, counter2 = 0;
	cin >> s;
	for (i = 0; i < s.size(); i++) {

		if (i % 2 == 0) {
			if (s[i] == '1') {
				counter1++;
				//cout << 'a';
			}
			else {
				counter2++;
				//cout << 'i';
			}
		}
		else {
			if (s[i] == '0') {
				counter1++;
				//cout << 'u';
			}
			else {
				counter2++;
				//cout << 'e';
			}
		}
		
	}

	if (counter1 < counter2) {
		cout << counter1 << endl;
	}
	else {
		cout << counter2 << endl;
	}

	return 0;
	*/
	//B
	/*int n;
	cin >> n;
	int i;
	int h[20];
	for (i = 0; i < n; i++) {
		cin >> h[i];
	}
	int maxh = 0;
	int hcounter = 0;
	maxh = h[0];
	hcounter++;
	for (i = 1; i < n; i++) {
		if (h[i] >= maxh) {
			maxh = h[i];
			hcounter++;
		}
	}
	cout << hcounter << endl;
	return 0;*/
	
	
	//A
	/*
	int a,b;
	cin >> a >> b;
	int x = 0;
	for (int i = 0; i < 2; i++) {
		if (a > b) {
			x = x + a;
			a--;
		}
		else {
			x = x + b;
			b--;
		}
	}
	cout << x << endl;
	return 0;
	*/


}