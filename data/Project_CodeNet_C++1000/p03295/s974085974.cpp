#include <bits/stdc++.h>
using namespace std;

int check_overlap(int &l, int &r, int l2, int r2);

int main()
{

	int n,m;
	cin >> n >> m;

	vector<pair<int,int>> request(m);
	for (int i=0;i<m;++i)
	{
		cin >> request[i].first >> request[i].second;
	}
	sort(request.begin(),request.end());

	int count=1;
	int left=request[0].first;
	int right=request[0].second;

	for (int i=1;i<m;++i)
	{
		if (check_overlap(left,right,request[i].first,request[i].second)==0)
		{
			// no overlap
			++count;
			left=request[i].first;
			right=request[i].second;
		}
	}

	cout << count << endl;


}

int check_overlap(int &l, int &r, int l2, int r2)
{
	// l<=l2 is guaranteed in this program
	if (l2<r)
	{
		// overlapped - update l & r to overlapped range
		l=l2;
		if (r2<r)
		{
			r=r2;
		}
		return 1;
	}
	else
	{
		// not overlapped
		return 0;
	}
}


