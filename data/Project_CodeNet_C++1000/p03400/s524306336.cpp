#include<iostream>
#include<vector>
using namespace std;
int choco(vector<int> a,int i,int d){
	int ret=0;
	do{
		ret++;
	} while (ret*a.at(i)+1<=d);
	return ret;

}
int main() {
	int n, d,x, sum = 0;
	cin >> n>>d>>x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a.at(i);
	}
	for (int i = 0; i < n; i++) {
		sum += choco(a,i,d);
	}
	cout << sum+x;
}