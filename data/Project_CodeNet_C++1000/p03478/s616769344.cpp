
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, A, B; cin >> N >> A >> B;
	int answer = 0;
	for (int i = 1; i <= N; ++i) {
		string numstr = to_string(i);
		int sum = 0;
		for (int n = 0; n < numstr.size(); ++n) {
			sum += numstr[n] - '0';
		}
		if (sum >= A && sum <= B) {
			answer += i;
		}
	}
	cout << answer << endl;

	return 0;
}
