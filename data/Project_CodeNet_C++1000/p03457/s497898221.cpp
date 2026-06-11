#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	int px=0, py=0, pt=0;
	int x,y,t;
	for(int i=1;i<=n;i++){
		cin>>t>>x>>y;
		int p=abs(x - px) + abs(y - py);
		int tt=(t-pt)-p;
		if(tt < 0 || tt%2) {
			cout << "No" << endl;
			return 0;
		}
		px=x, py=y, pt=t;
	}
	cout<<"Yes"<<endl;
	return 0;
}