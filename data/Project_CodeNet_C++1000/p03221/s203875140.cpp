#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int N,M;
	int *P,*Y;
	std::vector<int> *yd;
	cin >> N >> M;
	yd = new std::vector<int>[N];
	P = new int[M];
	Y = new int[M];

	for(int i=0;i<M;i++)
	{
		cin >> P[i] >> Y[i];
		yd[P[i]-1].push_back(Y[i]);
	}

	for(int i=0;i<N;i++)
	{
		sort(yd[i].begin(),yd[i].end());
	}

	for(int i=0;i<M;i++)
	{
		int index = P[i] - 1;
		int rank = int(lower_bound(yd[index].begin(),yd[index].end(),Y[i]) - yd[index].begin()) + 1;
		printf("%06d%06d\n",P[i],rank);
	}

	return 0;
}