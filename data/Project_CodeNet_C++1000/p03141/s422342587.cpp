#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

struct dish{
	int value;
	int id;
	
	bool operator<(const dish& another) const {
		if(value != another.value) return value > another.value;
		return id < another.id;
	}
};

int main(){
	
	int n;
	cin >> n;
	vector<int> a(n),b(n);
	vector<dish> dishes(n);
	
	rep(i,n){
		cin >> a[i] >> b[i];
		dishes[i] = dish{a[i]+b[i],i};
	}
	
	sort(dishes.begin(), dishes.end());
	
	ll res = 0;
	int i = 0;
	while(i < n){
		res += a[dishes[i].id];
		if(++i != n) res -= b[dishes[i].id];
		i++;
	}
	
	cout << res << endl;
	return 0;
}
