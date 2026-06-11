#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
set<string> subs; 

int main()
{
	string s;
	cin >> s;
	int K;
	cin >> K;
	int N = s.size();
	for (int i = 0; i < N; ++i)
	{
		string temp = "";
		for (int j = i; ((j < N) & (j <= i + 4)); ++j)
		{
			temp += s[j];
			subs.insert(temp);
		}
	}

	auto it = subs.begin();
	/*
	while(it != subs.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	it = subs.begin();
	*/
	rep(i,K-1)
	{
		it++;
	}
	cout << *it << endl;
	return 0;
}