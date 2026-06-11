#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(auto& x:a){
		cin >> x;
	}
	sort(a.begin(), a.end());
	vector<int> b;
	int c = 1;
	for(int i =1; i< n; i++){
		if(a.at(i) == a.at(i-1)) c++;
		if(a.at(i) != a.at(i-1)){
			b.push_back(c);
			c=1;
		}
		if(i == n-1) b.push_back(c);
	}
	int u = b.size()-k;
	sort(b.begin(), b.end());
	if(u<0) u = 0;
	int sum = 0;
	for(int i = 0; i < u; i++){
		sum += b.at(i);
	}
	cout << sum <<endl;

}
