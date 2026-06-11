#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
using namespace std;
long long  mod = 1000000007;
int main()
{
	char S[20];
	cin >> S;
	int i = 0;
	int count = 0;
	while (S[i] != '\0') {
		if (S[i] == 'x') count++;
		i++;
	}
	if (count >= 8) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}
}