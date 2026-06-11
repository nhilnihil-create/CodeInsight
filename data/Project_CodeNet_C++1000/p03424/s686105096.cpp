#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;
	char S[N];
	string Ans = "Three";

	for(int i = 0; i < N; i++){
		cin >> S[i];
		if (S[i] == 'Y') {
			Ans = "Four";
		}
 	}
	cout << Ans << '\n'; //答えの出力

	return 0;
}