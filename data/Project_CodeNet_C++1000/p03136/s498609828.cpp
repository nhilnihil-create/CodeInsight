#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
int main(){
	int N;
	cin >> N;
	vector<int>a(N);
	for(auto&e:a)cin >> e;
	int acc = accumulate(a.begin(),a.end(),0);
	int ma = *max_element(a.begin(),a.end());
	acc -= ma;
	if(ma < acc)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}