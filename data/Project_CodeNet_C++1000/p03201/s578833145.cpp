#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<set>
#include<queue>
#include<cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	multiset<int,greater<int> > a;
	for(int i=0;i<n;i++)
	{
		int tmp;
		cin >> tmp;
		a.insert(tmp);
	}

	vector<long long> pow2;
	for(int i=0;i<1000;i++)
	{
		pow2.push_back(pow(2,i));
		if(pow(2,i)>10000000000)break;
	//	cout << pow2[i] << endl;
	}

	int cnt=0;
	while(true)
	{
		auto itr=a.begin();
		if(itr==a.end())break;
		int now=*itr;
		a.erase(itr);
	//	cout << now << endl;
		int target=0;
		for(int i=0;i<pow2.size();i++)
			if(pow2[i]>now)
			{
				target=pow2[i];
				break;
			}
		auto finditr=a.find(target-now);
		if(finditr==a.end())
			continue;
		else
		{
			cnt++;
			a.erase(finditr);
			cerr << now << " " << target-now << endl;
		}

	}

	cout << cnt << endl;




}