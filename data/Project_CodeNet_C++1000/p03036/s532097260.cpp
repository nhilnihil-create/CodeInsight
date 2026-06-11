#include <iostream>
using namespace std;

int main() {
int r; cin>> r;
int D; cin>> D;
int wt; cin>>wt;
for(int a=1; a<11; a++){
	wt= (r*wt)-D;
	cout<< wt<< endl;
}
	return 0;
}