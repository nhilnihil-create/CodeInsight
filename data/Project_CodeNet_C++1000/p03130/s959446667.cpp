#include <iostream>
using namespace std;

int main() {
	int v[4] = {0,0,0,0};
	for(int i=0;i<3;++i){
		int a,b;cin>>a>>b;
		++v[a-1];
		++v[b-1];
	}
	int cnt1 = 2;
	int cnt2 = 2;
	for(int i=0;i<4;++i){
		if(v[i]==1) --cnt1;
		if(v[i]==2) --cnt2;
	}
	if(cnt1==0&&cnt2==0){
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}