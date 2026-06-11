#include<iostream>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<algorithm>//min,max,swap,rand,reverse,sort,lower_bound
#include<functional>
#include<vector>
#include<list>
#include<map>
#include<tuple>
#include<cmath>//abs, sin, cos
#include<bitset>
using namespace std;

int main()
{
	int N,t, p,sum=0, cost=0;
	vector<int> C, V;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t;
		C.push_back(t);
	}
	for (int i = 0; i < N; i++) {
		cin >> p;
		V.push_back(p);
	}

	for (int i = 0; i < N; i++) {
		if (C[i] > V[i]) {
			sum += C[i];
			cost += V[i];
		}
	}

	cout << sum - cost << endl;

	return 0;
}