#include <bits/stdc++.h>
using namespace std;

int K, genap, ganjil;

int main () {
	cin >> K;
	genap = K/2;
	ganjil = K-genap;
	cout << genap * ganjil;
}