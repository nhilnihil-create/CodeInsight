#include <iostream>
#include <vector>
using namespace std;
 
int main(){
	int n; cin >> n; int x[n], y[n], xy[2]={0,0};
	for(int i=0; i<n; i++) {
		cin >> x[i] >> y[i];
		xy[(x[i]+y[i])%2]=1;
	}
	if (xy[0] && xy[1]) {cout << -1 << endl; return 0;}
	vector<int> v;
	if (xy[0]) v.push_back(1);
	for(int i=1<<30; i>0; i>>=1) {
		v.push_back(i);
	}
	cout << v.size() << endl;
	for(int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	} cout << endl;
	for(int i=0; i<n; i++) {
		int xx=0, yy=0;
		for(int j=0; j<v.size(); j++){
			if (abs(x[i]) > abs(y[i])) {
				if (x[i] > 0) {x[i]-=v[j]; cout << "R";}
				else {x[i]+=v[j]; cout << "L";}
			} else {
				if (y[i] > 0) {y[i]-=v[j]; cout << "U";}
				else {y[i]+=v[j]; cout << "D";}
			}
		}
		cout << endl;
	}
}