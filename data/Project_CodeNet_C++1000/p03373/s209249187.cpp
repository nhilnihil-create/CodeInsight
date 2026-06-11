#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	vector<int> vec(100001);
	for(int i=0; i<=100000; i++){
		vec.at(i)=i*2*c+max(0,x-i)*a+max(0,y-i)*b;
	}
	sort(vec.begin(), vec.end());
	cout << vec.at(0) << endl;
}

