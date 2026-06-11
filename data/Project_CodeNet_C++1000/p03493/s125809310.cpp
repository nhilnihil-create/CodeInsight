#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
	int S, S1, S2, S3;
	cin >> S;
	S1 = S / 100;
	S2 = (S - (S1 * 100)) / 10;
	S3 = S - (S1 * 100) - (S2 * 10);
	cout << S1 + S2 + S3 << endl;
}