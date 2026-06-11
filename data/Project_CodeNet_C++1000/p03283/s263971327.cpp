#include<iostream>
#include<algorithm>
using lint = int_least64_t;
using namespace std;

#include<vector>
template<typename T>
class SegmentTree
{
	public:

	int N;
	vector<T> tree;

	T unit;
	T (*func)(T, T);

	SegmentTree(vector<T>& src, T unit, T (*func)(T, T))
	{
		this->unit = unit;
		this->func = func;

		const int size = (int)src.size();
		N = 1;
		while(N < size)
			N *= 2;

		tree.resize(2*N - 1);
		for(int i = 0; i < N; i++)
			tree[i] = unit;

		for(int i = 0; i < size; i++)
			update(i, src[i]);
	}

	void update(int i, const T value)
	{
		i = i + N-1;

		tree[i] = value;
		while(i > 0)
		{
			i = (i - 1) / 2;
			tree[i] = func(tree[2*i+1], tree[2*i+2]);
		}
	}

	T get(int i)
	{
		return tree[i + N-1];
	}

	T answer(int tl, int tr, int l = 0, int r = -1, int i = 0)
	{
		if(r < 0)
			r = N;

		if(tr <= l || r <= tl)
			return unit;

		if(tl <= l && r <= tr)
			return tree[i];

		const T ansl = answer(tl, tr, l, (l+r)/2, 2*i+1);
		const T ansr = answer(tl, tr, (l+r)/2, r, 2*i+2);

		return func(ansl, ansr);
	}

};

int add(int x, int y)
{
	return x + y;
}

bool cmp(const pair<int, pair<int, int>>& x, const pair<int, pair<int, int>>& y)
{
	int xf  = x.first;
	int xss = x.second.second;
	int yf  = y.first;
	int yss = y.second.second;

	if(xss == yss)
		return xf < yf;
	return xss < yss;
}

int main()
{
	int N, M, Q;
	vector<pair<int, pair<int, int>>> v;
	int p[100010] = {};
	int q[100010] = {};

	cin >> N >> M >> Q;
	for(int i = 0; i < M; i++)
	{
		int L, R;
		cin >> L >> R;
		v.push_back({0, {L-1, R}});
	}
	for(int i = 0; i < Q; i++)
	{
		cin >> p[i] >> q[i];
		p[i]--;
		v.push_back({1, {p[i], q[i]}});
	}

	sort(v.begin(), v.end(), cmp);

	vector<int> src(N, 0);
	SegmentTree<int> sg(src, 0, add);
	int ans[510][510] = {};
	for(auto&& p: v)
	{
		int l = p.second.first;
		int r = p.second.second;
		bool isquery = (p.first == 1);
		
		if(isquery)
			ans[l][r] = sg.answer(l, r);
		else
			sg.update(l, sg.get(l)+1);
	}

	for(int i = 0; i < Q; i++)
		cout << ans[p[i]][q[i]] << endl;
		
	return 0;
}

