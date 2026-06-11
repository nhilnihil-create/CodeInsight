#include <iostream>
#include <cstdio>
#include <deque>
#define N 100005
using namespace std;

int k;
bool v[N];
deque<int> qu, qc;
int main()
{
	int fu, fc, ne;
	cin >> k;
	qu.push_front(1);
	qc.push_front(1);
	while (!qu.empty()) {
		fu = qu.front(), qu.pop_front();
		fc = qc.front(), qc.pop_front();
		if (fu == 0) {cout << fc; return 0;}
		if (v[fu]) continue;
		v[fu] = 1;
		ne = fu * 10 % k;
		if (!v[ne]) qu.push_front(ne), qc.push_front(fc);
		ne = (fu + 1) % k;
		if (!v[ne]) qu.push_back(ne), qc.push_back(fc + 1);
	}
    return 0;
}