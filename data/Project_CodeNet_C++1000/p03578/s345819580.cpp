#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;



int main(){
	int n;
	cin >> n;
	map<int,int> have;
	rep(i,n){
		int input;
		cin >> input;
		have[input]++;
	}	
	int m;
	cin >> m;
	map<int,int> prob;
	rep(i,m){
		int input;
		cin >> input;
		have[input]--;
	}
	for(auto a:have){
		if(a.second<0){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
