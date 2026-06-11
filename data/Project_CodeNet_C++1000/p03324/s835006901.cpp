#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int D, N;

int cal(int x)
{
	int res = 0;
	while(x%100 == 0){
		x/=100;
		res++;
	}
	return res;
}

void solve()
{
	vector<int> ans;
	for(int i=1;;++i){
		if(cal(i) == D){
			ans.push_back(i);
			if((int)ans.size() == N){
				cout << ans.back() << '\n';
				return;
			}
		}
	}
}

int main()
{
	cin >> D >> N;
	solve();
	return 0;
}