#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v(4);
	cin >> v[0]>> v[1]>> v[2]>> v[3];
	sort(v.begin(),v.end());
	if(v[0]==1 &&v[1]==4 &&v[2]==7 &&v[3]==9){
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}