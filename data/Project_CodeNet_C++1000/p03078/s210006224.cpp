#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;
using PL = pair<ll,ll>;


int main()
{
	int x, y, z, k;
	cin >> x >> y >> z >> k;
	vector<ll> a(x), b(y), c(z);
	for(int i = 0; i < x; i++)cin >> a[i]; sort(a.begin(), a.end(), greater<ll>());
	for(int i = 0; i < y; i++)cin >> b[i]; sort(b.begin(), b.end(), greater<ll>());
	for(int i = 0; i < z; i++)cin >> c[i]; sort(c.begin(), c.end(), greater<ll>());
	using T = tuple<ll,int,int,int>;
	priority_queue<T> que;
	set<T> st;
	que.emplace(a.front() + b.front() + c.front(), 0, 0, 0);
	st.emplace(a.front() + b.front() + c.front(), 0, 0, 0);
	vector<ll> ans;


	for(int i = 0; i < k; i++) {
		auto cur = que.top();
		ans.push_back(get<0>(cur));
		que.pop();
//		cerr << get<0>(cur) << " :: " << get<1>(cur) << " :: " << get<2>(cur) << " :: " << get<3>(cur) << endl;
		T nx1, nx2, nx3;
		if(get<1>(cur) + 1 < x)
		nx1 = T(get<0>(cur) + a[get<1>(cur) + 1] - a[get<1>(cur)], get<1>(cur) + 1, get<2>(cur), get<3>(cur));

		if(get<2>(cur) + 1 < y)
		nx2 = T(get<0>(cur) + b[get<2>(cur) + 1] - b[get<2>(cur)], get<1>(cur), get<2>(cur) + 1, get<3>(cur));

		if(get<3>(cur) + 1 < z)
		nx3 = T(get<0>(cur) + c[get<3>(cur) + 1] - c[get<3>(cur)], get<1>(cur), get<2>(cur), get<3>(cur) + 1);

		if(!st.count(nx1)) {
			que.push(nx1);
			st.insert(nx1);
		}

		if(!st.count(nx2)) {
			que.push(nx2);
			st.insert(nx2);
		}

		if(!st.count(nx3)) {
			que.push(nx3);
			st.insert(nx3);
		}

	}

	for(auto i : ans) {
		cout << i << endl;
	}

}