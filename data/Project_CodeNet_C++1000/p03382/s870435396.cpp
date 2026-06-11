#include <cstdio>
#include <set>
#include <algorithm>
//#pragma warning(disable:4996)


using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int mmx = 0;
	set<int> st;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		if (mmx < x)
			mmx = x;
		st.insert(x);
	}
	int val = mmx / 2;
	auto it = st.lower_bound(val);
	int id = 0;
	if (it != st.end() && *it != mmx)
		id = *it;
	if (it != st.begin())
	{
		--it;
		if (min(*it, mmx - *it) > min(id, mmx - id))
			id = *it;
	}
	printf("%d %d", mmx, id);
}