#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,t,a;
	cin >> n >> t >> a;
	vector<double> temperatures;
	for(int i=0; i<n; i++){
		int height;
		cin >> height;
		temperatures.push_back(abs(t-height*0.006-a));
	}
	int minElementIndex = min_element(temperatures.begin(),temperatures.end()) - temperatures.begin();
	cout << minElementIndex+1;
	return 0;
}