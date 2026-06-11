#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, unsigned int> P;

// Streamline
int main() {
	unsigned int N, M;
	vector<int> X;
	// x is for input only
	int x;
	// input value
	cin >> N >> M;
	for (unsigned int i = 0; i < M; i++)
	{
		cin >> x;
		X.push_back(x);
	}
	// exception
	if (M == 1)
	{
		cout << 0;
		return 0;
	}
	// sort X in a descending order
	sort(begin(X), end(X));

	// "sub" stores difference of X and subscript of X
	vector<P> sub;
	// p is for input only
	P p;
	for (unsigned int i = 1; i < M; i++)
	{
		p.first = X[i] - X[i - 1];
		p.second = i;
		sub.push_back(p);
	}
	// sort sub in a ascending order
	sort(begin(sub), end(sub), greater<>());

	// "group" stores efficient group division of X
	vector<unsigned int> group;
	group.push_back(0);
	group.push_back(M - 1);
	// if piece is more than coordinate
	if (N > M) N = M;
	for (unsigned int i = 0; i < N - 1; i++)
	{
		group.push_back(sub[i].second);
		group.push_back(sub[i].second - 1);
	}
	// sort group in a descending order
	sort(begin(group), end(group));
	
	unsigned int count = 0;
	for (unsigned int i = 1; i <= N * 2; i += 2)
	{
		count += X[group[i]] - X[group[i - 1]];
	}
	cout << count;
}