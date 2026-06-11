#include <iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;






int main()
{
	int N;
	cin >> N;

	int num;

	set<int> st;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		st.insert(num);
	}

	cout << st.size();
}

