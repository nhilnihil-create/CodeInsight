#include <iostream>
using namespace std;

int main() {
	int n,a,b;cin >> n;
	cin >> a>> b;
	int cnt_a =0;
	int cnt_b =0;
	int cnt_c =0;
	for(int i=0;i<n;++i) {
		int t;cin>>t;
		if(t<=a){
			++cnt_a;
		} else if(t>a && t<=b){
			++cnt_b;
		} else {
			++cnt_c;
		}
	}
	int out = min(cnt_a,cnt_b);
	out = min(out,cnt_c);
	cout << out << endl;
	return 0;
}