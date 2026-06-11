#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	int n;cin >> n;
	string a,b,c;
	cin >>a;
	cin >>b;
	cin >>c;
	int cnt =0;
	for(int i=0;i<n;++i){
		set<char> st;
		st.insert((char)a[i]);
		st.insert((char)b[i]);
		st.insert((char)c[i]);
		if(st.size()==2)++cnt;
		if(st.size()==3)cnt+=2;
	}
	cout << cnt << endl;
	return 0;
}