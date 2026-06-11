#include<bits/stdc++.h>
using namespace std;

const int N = 50;
int arr[N + 5];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin>>n;
	int posmax = 0, negmax = 0;
	for(int i = 1;i <= n;i++) {
		cin>>arr[i];
		if(arr[i] >= 0) posmax = max(posmax, arr[i]);
		else negmax = max(negmax, -arr[i]);
	}
	int target = posmax;
	if(posmax <= negmax) target = -negmax;
	int idx = 1;
	for(int i = 1;i <= n;i++) {
		if(target == arr[i]) idx = i;
	}
	vector<pair<int,int> > res;
	for(int i = 1;i <= n;i++) {
		arr[i] += arr[idx];
		res.push_back({idx, i});
	}
	if(arr[1] >= 0) {
		for(int i = 2;i <= n;i++) {
			arr[i] += arr[i - 1];
			res.push_back({i - 1, i});
		}
	} else {
		for(int i = n - 1;i >= 1;i--) {
			arr[i] += arr[i + 1];
			res.push_back({i + 1, i});
		}		
	}
	cout<<res.size()<<endl;
	for(int i = 0;i < res.size();i++) cout<<res[i].first<<" "<<res[i].second<<endl;
}