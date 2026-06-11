#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	int p[n];
	int one = 0,two=0,three=0;
	for(int i = 0; i < n; i++){
		cin >>p[i];
		if(p[i]<=a)one++;
		else if(p[i]<=b)two++;
		else three++;
	}
	cout << min(one, min(two,three)) << endl;
	return 0;
}
