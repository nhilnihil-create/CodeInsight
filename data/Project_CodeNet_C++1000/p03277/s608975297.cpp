#include <iostream>
#include <map>
#include <vector>
#define llint long long

using namespace std;

struct BIT{
	int size;
	vector<llint> bit;
	BIT(){size = 0;}
	BIT(int s){
		size = s;
		bit.resize(size+1);
		init();
	}
	void init(){
		for(int i = 1; i <= size; i++) bit[i] = 0;
	}
	llint query(int i){
		llint ret = 0;
		while(i > 0){
			ret += bit[i];
			i -= i&(-i);
		}
		return ret;
	}
	void add(int i, llint x){
		while(i <= size){
			bit[i] += x;
			i += i&(-i);
		}
	}
};

llint n;
llint a[100005];
llint s[100005];
map<llint, llint> mp;
BIT bit(100005);

bool check(llint x)
{
	s[0] = 0;
	for(int i = 1; i <= n; i++){
		s[i] = s[i-1];
		if(a[i] <= x) s[i]++;
		else s[i]--;
	}
	
	mp.clear();
	for(int i = 0; i <= n; i++) mp[s[i]];
	llint id = 1;
	for(auto it = mp.begin(); it != mp.end(); it++) it->second = id++;
	for(int i = 0; i <= n; i++) s[i] = mp[s[i]];
	
	llint cnt = 0;
	bit.init();
	for(int i = 0; i <= n; i++){
		cnt += bit.query(s[i]-1);
		bit.add(s[i], 1);
	}
	return cnt >= n*(n+1)/2/2+1;
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint ub = 1e9+7, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	cout << ub << endl;
	return 0;
}