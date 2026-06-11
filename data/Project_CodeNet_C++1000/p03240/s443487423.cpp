#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n;
	cin>>n;
	vector<int> x(n), y(n), h(n);
	for(int i = 0; i < n; i++){
		cin>>x[i]>>y[i]>>h[i];
	}
	for(int cx = 0; cx <= 100; cx++){
		for(int cy = 0; cy <= 100; cy++){
			set<int> st;
			int lim = 2e9;
			for(int i = 0; i < n; i++){
				if(h[i])st.insert(h[i] + abs(cx - x[i]) + abs(cy - y[i]));
				else lim = min(lim, abs(cx - x[i]) + abs(cy - y[i]));
			}
			if(st.empty()){
				cout<<cx<<" "<<cy<<" "<<lim<<endl;
				exit(0);
			}
			if(st.size() == 1 && (*st.begin()) <= lim){
				cout<<cx<<" "<<cy<<" "<<(*st.begin())<<endl;
				exit(0);
			}
		}
	}

	return 0;
}