#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()

int main(){
	int N;
	cin >> N;
	int ol, nw, cnt = 0;
	cin >> ol;
	for (int i = 1;i < N;i++) {
		cin >> nw;
		if (nw == ol) {
			nw = 10000;
			cnt++;
		}
		swap(ol, nw);
	}
	cout << cnt << endl;
}