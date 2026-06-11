#include <bits/stdc++.h>

using namespace std;

#define MIN 0
int n;	
vector <long long int> H,A;
vector <long long int> tree;

void update(int node, int start, int end, int left, int right,long long int val)
{
	if(left > end || right < start)
	{
		return;
	}
	if (left <= start && end <= right)
	{
		tree[node] = max(tree[node],val);
		return;
	}	
	int mid = (start + end) / 2;
	update(node * 2, start, mid, left, right, val);
	update(node * 2 + 1, mid + 1, end, left, right, val);
	tree[node] = max(tree[node],max(tree[node * 2],tree[node * 2 + 1]));
}

long long int find(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
	{
		return MIN;
	}

	if (left <= start && end <= right)
	{
		return tree[node];
	}

	int mid = (start + end) / 2;
	return max(find(node * 2, start, mid, left, right), find(node * 2 + 1, mid + 1, end, left, right));
}


int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	int h = (int)ceil(log2(200010));
	int size = (1 << (h + 1)) - 1;
	tree.resize(size);
	
	for(int i=0;i<n;i++)
	{
		int t;
		cin >> t;
		H.push_back(t);
	}

	for(int i=0;i<n;i++)
	{
		int t;
		cin >> t;
		A.push_back(t);
	}

	for (int i = 0; i < n; i++)
	{
		long long int val = find(1,0,n,0,H[i]-1);
		val += A[i];
		update(1,0,n,H[i],H[i],val);
		//cout << minfind(1, 0, n, a, b) << ' ' << maxfind(1, 0, n - 1, a, b) << '\n';
	}

	cout << find(1,0,n,0,n) << '\n';

	return 0;
}