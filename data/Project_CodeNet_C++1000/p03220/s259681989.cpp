	#include <iostream>
	#include <string>
	#include <vector>
	#include <algorithm>
	#include <utility>
	#include <map>
	using namespace std;
	typedef long long ll;
	#define rep(i,n) for (int i=0;i < (int)(n);i++)


	int main(){
		int n;
		double t,a;
		cin >> n >> t >> a;
		vector<int> v(n);
		rep(i,n) cin >> v[i];
		int id = 0;
		double now = 1e9;
		for (int i = 0;i < n;i++){
			if (abs(a - (t - double(v[i])*(0.006))) < now){
				id = i+1;
				now = abs(a -(t - double(v[i])*(0.006)));
			}
		}
		cout << id << endl;


		
		return 0; 
	}

