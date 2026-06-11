#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

vector<int> vec;

void pre(){
	set<int> st({3, 5, 7});
	for(auto x : st){
		int y = x;
		int dig = 0;
		while(y){
			dig++; y /= 10;
		}
		if(dig == 9)break;
		st.insert(x*10 + 3);
		st.insert(x*10 + 5);
		st.insert(x*10 + 7);
	}
	for(auto x : st){
		int y = x;
		vector<int> f(10, 0);
		while(y){
			f[y%10]++; y /= 10;
		}
		if(f[3] && f[5] && f[7])vec.push_back(x);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	pre();
	int n;
	cin>>n;
	cout<<(upper_bound(vec.begin(), vec.end(), n) - vec.begin())<<endl;

	return 0;
}