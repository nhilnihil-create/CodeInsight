#include <iostream>
using namespace std;

int main() {
	int a,b,c; cin >>a>>b>>c;
	if(a<b){
		if(a<c && c<b){
			cout << "Yes";
		} else {
			cout << "No";
		}
	} else {
		if(a>c && c>b){
			cout << "Yes";
		} else {
			cout << "No";
		}
	}
	return 0;
}