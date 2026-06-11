#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void)
{
	int N, K;

	cin >> N;

	cin >> K;

	int odd = N % 2;
	//cout << odd;
	if (K <=(N / 2 + odd))
		cout << "YES";

	else
		cout << "NO";


}