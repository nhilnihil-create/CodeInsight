#include <bits/stdc++.h>
#define booga cout << "booga" << endl
#define ll long long int
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,t;
	cin >> n >> t;
	vector<pair<int,int>> p(n);
	for(int i{0};i < n;i++){
		cin >> p[i].first >> p[i].second;
	}
	sort(p.begin(),p.end());
	for(int i{0};i < n;i++){
		if(p[i].second <= t){
			cout << p[i].first;
			return 0;
		}
	}
	cout << "TLE";
	return 0;
}



