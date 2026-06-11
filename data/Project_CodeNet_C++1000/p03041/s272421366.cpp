#include <bits/stdc++.h>
using namespace std;

int N, K, cnt;
string S;
char c;

int main () {
	cin >> N >> K >> S;
	c = S[K-1];
	cnt = c+32;
	S[K-1]=(char)cnt;
	cout << S;
}