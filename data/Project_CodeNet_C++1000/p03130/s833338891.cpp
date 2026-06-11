#include <iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> a(3),b(3),c(4);
	for(int i=0;i<3;i++){
		cin>>a[i]>>b[i];
		c[a[i]-1]++;
		c[b[i]-1]++;
	}
	for(int i=0;i<4;i++){
		if(c[i]==3){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;

	return 0;
}
