#include <vector>
#include <iostream>

int main() {
	using std::cin;
	int n, m;

	std::vector<std::string> blue, red;

	scanf("%d\n", &n);
	blue.resize(n);
	for (int i = 0; i < n; i++)
		cin >> blue[i];

	scanf("%d\n", &m);
	red.resize(m);
	for (int i = 0; i < m; i++)
		cin >> red[i];

	int r = 0;
	for (int i = 0; i < n - 1; i++) {
		int count = 1;
		for (int j = i + 1; j < n; j++) {
			if (blue[i] == blue[j]) ++count;
		}
		for (int k = 0; k < m; k++) {
			if (blue[i] == red[k]) --count;
		}
		r = std::max(r, count);
	}

	printf("%d\n", r);

	return 0;
}
