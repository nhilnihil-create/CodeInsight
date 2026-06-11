#include <iostream>
#include <vector>

using namespace std;
void judge(vector<int>& vec_t)
{
	vector<int>::iterator i, j;
	int temp = 0;
	int sum_t=0;
	for (i = vec_t.begin(), j = vec_t.begin();i != vec_t.end();i++)
		if (*i > * j) j = i;
	temp = *j;
	vec_t.erase(j);
	for (i = vec_t.begin();i != vec_t.end();i++)
		sum_t += *i;
	if (sum_t > temp)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return;

}

int main()
{
	int n,i,temp;
	vector<int> vec_t;
	cin >> n;
	for (i = 0;i < n;i++)
	{
		cin >> temp;
		vec_t.push_back(temp);
	}
	judge(vec_t);
	return 0;
}